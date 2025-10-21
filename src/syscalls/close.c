#include <constants.h>
#include <syscall.h>

int close(int fd) { return (int)syscall1(SYS_CLOSE, fd); }