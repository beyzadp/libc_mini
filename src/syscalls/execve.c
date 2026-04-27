#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

int execve(const char *filename, char *const argv[], char *const envp[]) {
    return (int)syscall3(SYS_EXECVE, (long)filename, (long)argv, (long)envp);
}
