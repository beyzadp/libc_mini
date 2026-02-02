#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

// int setsockopt(int socket, int level, int option_name,
//     const void *option_value, socklen_t option_len);

// The setsockopt() function shall set the option specified by the option_name
// argument, at the protocol level specified by the level argument, to the value
// pointed to by the option_value argument for the socket associated with the
// file descriptor specified by the socket argument.

//    Upon successful completion, setsockopt() shall return 0. Otherwise, -1
//    shall be returned and errno set to indicate the error.

int setsockopt(int socket, int level, int option_name, const void *option_value,
               socklen_t option_len) {
    return (int)syscall5(SYS_SETSOCKOPT, socket, level, option_name,
                         (long)option_value, option_len);
}