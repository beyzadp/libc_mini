#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

// int listen(int socket, int backlog);

int listen(int sockfd, int backlog) {
  return (int)syscall2(SYS_LISTEN, sockfd, backlog);
}