#include <constants.h>
#include <e_lib.h>
#include <mini_netinet_in.h>
#include <syscall.h>
#define BUFFER_SIZE 4096

int main(void) {
    const char *http_200 = "HTTP/1.0 200 OK\r\n\r\n";
    const char *http_404 = "HTTP/1.0 404 Not Found\r\n\r\n";
    const char *new_line = "\n";
    struct sockaddr_in server;
    int sockfd = socket(AF_INET, 1, 0); // AF_INET, SOCK_STREAM, protocol
    server.sin_addr.s_addr = 0;         // any address (0.0.0.0)
    server.sin_port = 0xD204;    // port 4444, since i dont have any htons
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

    // parsing the filename

    // assume it is a get req

    size_t get_len = 4;
    const char *path_start = buffer + get_len;
    const char *path_end = e_strchr(path_start, ' ');

    size_t path_length = path_end - path_start;
    // writing the filename for debug
    path_start += 1;
    write(1, path_start, path_length);
    write(1, new_line, e_strlen(new_line));

    // opening, reading and writing the file content:
    char content[BUFFER_SIZE];

    //         mov byte ptr [r11 + r12], 0 # this tells open where to stop
    //  since path_end already is ' ' i dont think we need to do anything about
    //  it.
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

    exit(0);
    //  read(file_fd, path_start, path_length);
    //   read
    //   write

    // close
}

// add new lines