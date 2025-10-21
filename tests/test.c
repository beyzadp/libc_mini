#include <constants.h>
#include <mini_netinet_in.h>
#include <syscall.h>
#define BUFFER_SIZE 4096

int main(void) {
  struct sockaddr_in server;
  int sockfd =
      socket(AF_INET, 1, 0);  // AF_INET, SOCK_STREAM, protocol //need to define
  server.sin_addr.s_addr = 0; // any address (0.0.0.0)
  server.sin_port = 0x5C11;   // port 4444, since i dont have any htons
  server.sin_family = AF_INET; // address family (ip v4)

  int res = bind(sockfd, (struct sockaddr *)&server, sizeof(server));
  listen(sockfd, 1);
  int client_fd = accept(sockfd, 0, 0); // accept
  char buffer[BUFFER_SIZE];

  ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);

  // int file_fd = open(buffer, O_RDONLY, 0);
  // int n = read(file_fd, buffer, BUFFER_SIZE - 1);
  // write(1, buffer, bytes_read);

  // parsing the filename

  // assume it is a get req

  size_t get_len = 4;
  const char *path_start = buffer + get_len;
  const char *path_end = strchr(path_start, ' ');

  size_t path_length = path_end - path_start;

  // open
  int file_fd = open(path_start, O_RDONLY, 0);
  // read(file_fd, path_start, path_length);
  //  read
  //  write

  write(client_fd, path_start, path_length);
}