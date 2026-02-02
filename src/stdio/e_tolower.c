#include <constants.h>
#include <e_lib.h>

int e_tolower(int c) {
    if (c >= 65 && c <= 90) {
        c += 32;
        return c;
    }
    return c;
}