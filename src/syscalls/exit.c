#include <constants.h>
#include <e_lib.h>
#include <syscall.h>
__attribute__((noreturn)) void exit(int status) {
    syscall1(SYS_EXIT, status);
    __builtin_unreachable(); // this tells the compiler you will never get here
}