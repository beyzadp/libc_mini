#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

//      int accept(int socket, struct sockaddr *restrict address,
//        socklen_t *restrict address_len);

int accept(int socket, struct sockaddr *restrict address,
           socklen_t *restrict address_len) {
    return (int)syscall3(SYS_ACCEPT, socket, (long)address, (long)address_len);
}