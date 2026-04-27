#include "constants.h"
#include "e_lib.h"
#include "syscall.h"

int unlink(const char *pathname) {
    return (int)syscall1(SYS_UNLINK, (long)pathname);
}
