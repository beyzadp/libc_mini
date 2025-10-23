#include <constants.h>
#include <e_lib.h>
#include <mini_netinet_in.h>
#include <syscall.h>

//    int bind(int sockfd, const struct sockaddr *addr,
//           socklen_t addrlen);

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
  return (int)syscall3(SYS_BIND, sockfd, (long)addr, addrlen);
}