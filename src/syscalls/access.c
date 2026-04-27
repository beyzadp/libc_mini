// access syscall

#include "constants.h"
#include "e_lib.h"
#include "syscall.h"

int access(const char *pathname, int mode) {
    return syscall2(SYS_ACCESS, (long)pathname, mode);
}