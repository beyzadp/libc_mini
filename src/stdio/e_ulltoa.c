#include "constants.h"
#include "e_lib.h"

char *e_ulltoa(unsigned long long value) {
    static char buffer[21]; // Max: 20 digits + NUL
    char *p = &buffer[20];
    *p = '\0';
    if (value == 0)
        *--p = '0';
    else {
        while (value) {
            *--p = '0' + (value % 10);
            value /= 10;
        }
    }
    return p;
}