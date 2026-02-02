#include <constants.h>
#include <e_lib.h>

//  The isascii() function shall test whether c is a 7-bit US-ASCII character
//  code.

// The isascii() function is defined on all integer values.

// RETURN VALUE

// The isascii() function shall return non-zero if c is a 7-bit US-ASCII
// character code between 0 and octal 0177 inclusive; otherwise, it shall
// return 0.

// check is it between 0 and decimal 127

int e_isascii(int c) {
    if (c >= 0 && c <= 127) {
        return 1;
    }
    return 0;
}
