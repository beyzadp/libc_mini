#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

pid_t wait(int *wstatus) { return waitpid(-1, wstatus, 0); }
