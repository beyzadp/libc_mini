#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

pid_t waitpid(pid_t pid, int *wstatus, int options) {
    return (pid_t)syscall4(SYS_WAIT4, pid, (long)wstatus, options, 0);
}
