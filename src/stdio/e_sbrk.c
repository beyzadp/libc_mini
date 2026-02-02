#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

void *sbrk(intptr_t increment) {
    // Query the current program break:
    void *current = (void *)syscall1(SYS_BRK, 0);
    if (increment == 0)
        return current;

    void *new_break = (char *)current + increment;
    void *result = (void *)syscall1(SYS_BRK, (intptr_t)new_break);
    if (result == new_break)
        return current; // Return old break, as POSIX sbrk does
    else
        return (void *)-1;
}
