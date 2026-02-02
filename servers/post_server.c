#include <constants.h>
#include <e_lib.h>
#include <mini_netinet_in.h>
#include <syscall.h>
#define BUFFER_SIZE 4096

int main(void) {
    const char *http_200 = "HTTP/1.0 200 OK\r\n\r\n";
    const char *http_404 = "HTTP/1.0 404 Not Found\r\n\r\n";
    const char *new_line = "\n";
    const char *content_length = "Content-Length: ";

    struct sockaddr_in server;
    int sockfd = socket(AF_INET, 1, 0); // AF_INET, SOCK_STREAM, protocol
    server.sin_addr.s_addr = 0;         // any address (0.0.0.0)
    server.sin_port = 0xD204;    // port 1234, since i dont have any htons
    server.sin_family = AF_INET; // address family (ip v4)

    // prevent blocking by time_wait

    int optval = 1;
    setsockopt(sockfd, 1 /*SOL_SOCKET*/, 2 /*SO_REUSEADDR*/, &optval,
               sizeof(optval));

    int res = bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    listen(sockfd, 1);
    int client_fd = accept(sockfd, 0, 0); // accept
    char buffer[BUFFER_SIZE];

    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);

    // the get req is in the buffer

    // to see what the req is:
    write(1, buffer, bytes_read);
    write(1, new_line, e_strlen(new_line));
    write(1, new_line, e_strlen(new_line));

    // parsing the filename

    // assume it is a post req

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
    //  since path_end already is ' ' i dont think we need to do anything about
    //  it.
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

        write(postfilefd, post_content, len_content); // write POST body to file
        write(1, "Req Successful\n", 16);

        write(client_fd, http_200, e_strlen(http_200));

    } else {
        write(1, "Could not find POST body\n", 25);
    } // add new lines
}