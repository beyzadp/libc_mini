// libc_mini/tests/test.c

#include <constants.h>
#include <e_lib.h>
#include <mini_netinet_in.h>
#include <string.h>
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
  server.sin_port = 0xD204;           // port 4444, since i dont have any htons
  server.sin_family = AF_INET;        // address family (ip v4)

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

  if (e_strstr(buffer, "POST")) {
    write(1, "this is a post req", 19);
  } else if (e_strstr(buffer, "GET")) {
    write(1, "this is a GET req", 19);
  }
}