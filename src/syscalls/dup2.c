#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

int dup2(int oldfd, int newfd) { return (int)syscall2(SYS_DUP2, oldfd, newfd); }
