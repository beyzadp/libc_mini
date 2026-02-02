#include <constants.h>
#include <e_lib.h>

int e_toupper(int c) {
    if (c >= 97 && c <= 122) {
        c -= 32;
        return c;
    }
    return c;
}