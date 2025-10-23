#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

pid_t fork(void) { return (int)syscall(SYS_FORK); }