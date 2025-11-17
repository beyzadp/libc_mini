#include <constants.h>
#include <e_lib.h>
#include <mini_netinet_in.h>
#include <syscall.h>
#define BUFFER_SIZE 4096

/*
START_SERVER:
    create TCP socket
    bind to IPv4:port 80, all interfaces
    listen for connections

    LOOP:
        accept a client connection
        fork process
        IF child:
            close server socket
            read HTTP request
            parse method and filename
            IF method == GET:
                open requested file for reading
                read contents
                send HTTP 200 OK
                send file contents
            ELSE IF method == POST:
                parse Content-Length
                find POST data start
                open requested file for writing
                write posted data to file
                send HTTP 200 OK
            exit
        ELSE (parent):
            close client connection
            repeat LOOP
    */

int main(void) {

  const char *http_200 = "HTTP/1.0 200 OK\r\n\r\n";
  const char *http_404 = "HTTP/1.0 404 Not Found\r\n\r\n";
  const char *new_line = "\n";
  const char *content_length = "Content-Length: ";

  struct sockaddr_in server;
  int sockfd = socket(AF_INET, 1, 0); // AF_INET, SOCK_STREAM, protocol
  server.sin_addr.s_addr = 0;         // any address (0.0.0.0)
  server.sin_port = 0xD204;           // port 4444, since i dont have any htons
  server.sin_family = AF_INET;        // address family (ip v4)

  // prevent blocking by time_wait

  int optval = 1;
  setsockopt(sockfd, 1 /*SOL_SOCKET*/, 2 /*SO_REUSEADDR*/, &optval,
             sizeof(optval));

  int res = bind(sockfd, (struct sockaddr *)&server, sizeof(server));
  listen(sockfd, 1);

  while (1) {

    int client_fd = accept(sockfd, 0, 0); // accept
    char buffer[BUFFER_SIZE];

    int pid = fork();

    if (pid == 0) {

      close(sockfd);

      ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);

      // the get req is in the buffer

      // to see what the req is:
      write(1, buffer, bytes_read);
      write(1, new_line, e_strlen(new_line));
      write(1, new_line, e_strlen(new_line));

      // post

      if (e_strstr(buffer, "POST")) {
        write(1, "this is a post req\n", 20);
        size_t get_len = 5;
        const char *path_start = buffer + get_len;
        const char *path_end = e_strchr(path_start, ' ');

        size_t path_length = path_end - path_start;
        // writing the filename for debug
        path_start += 1;
        write(1, "file to write:", 15);
        write(1, new_line, e_strlen(new_line));

        write(1, path_start, path_length);
        write(1, new_line, e_strlen(new_line));

        // opening, reading and writing the file content:
        char content[BUFFER_SIZE];

        //         mov byte ptr [r11 + r12], 0 # this tells open where to stop
        //  since path_end already is ' ' i dont think we need to do anything
        //  about it.
        // well we do because open is looking for \0, not ' '

        *(char *)path_end = '\0';

        // check if found

        /*                parse Content-Length
                        find POST data start
                        open requested file for writing
                        write posted data to file
                        send HTTP 200 OK

        */
        // parse contentlength

        int len_content = 0;
        const char *pos = NULL;
        pos = e_strestr(buffer, content_length, 4096);

        if (pos) {
          pos += e_strlen(content_length);
          // Skip whitespace
          while (*pos == ' ' || *pos == '\t')
            pos++;
          // Parse digits
          while (*pos >= '0' && *pos <= '9')
            len_content = len_content * 10 + (*pos++ - '0');
        }

        // now len_content has the length of the content
        // i double checked this. its working.

        int postfilefd = open(path_start, O_WRONLY | O_CREAT | O_TRUNC,
                              S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

        const char *post_content = e_strestr(buffer, "\r\n\r\n", 4096);

        if (post_content) {
          post_content += 4; // Skip exactly past the separator

          write(postfilefd, post_content,
                len_content); // write POST body to file

          close(postfilefd);
          write(1, "Req Successful\n\n", 16);
          write(1, "----------\n", 12);

          write(client_fd, http_200, e_strlen(http_200));

        } else {
          write(1, "Could not find POST body\n", 25);
        } // add new lines

      }

      // get
      //
      else if (e_strstr(buffer, "GET")) {
        write(1, "this is a GET req", 19);
        write(1, new_line, e_strlen(new_line));

        size_t get_len = 4;
        const char *path_start = buffer + get_len;
        const char *path_end = e_strchr(path_start, ' ');

        size_t path_length = path_end - path_start;
        // writing the filename for debug
        path_start += 1;
        write(1, "file to write:", 14);
        write(1, path_start, path_length);
        write(1, new_line, e_strlen(new_line));

        // opening, reading and writing the file content:
        char content[BUFFER_SIZE];

        //         mov byte ptr [r11 + r12], 0 # this tells open where to stop
        //  since path_end already is ' ' i dont think we need to do anything
        //  about it.
        // well we do because open is looking for \0, not ' '

        *(char *)path_end = '\0';
        int file_fd = open(path_start, O_RDONLY, 0);

        if (file_fd < 0) {
          write(client_fd, http_404, e_strlen(http_404));
          close(client_fd);
          return 1;
        }

        ssize_t bytes_file = read(file_fd, content, sizeof(content) - 1);

        close(file_fd);
        write(client_fd, http_200, e_strlen(http_200));
        write(client_fd, content, bytes_file);
        write(client_fd, new_line, sizeof("\n") - 1);

        write(1, "Req Successful\n\n", 17);
        write(1, "----------\n", 12);
      }
      return 0;

    } else {
      close(client_fd);
    }
  }
  return 0;
}