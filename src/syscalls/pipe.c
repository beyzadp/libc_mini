#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

int pipe(int pipefd[2]) { return (int)syscall1(SYS_PIPE, (long)pipefd); }
