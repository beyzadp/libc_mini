
#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

// int socket(int domain, int type, int protocol);

int socket(int domain, int type, int protocol) {
  return (int)syscall3(SYS_SOCKET, domain, type, protocol);
}