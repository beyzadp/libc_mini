#include <constants.h>
#include <e_lib.h>

// int isdigit(int c);

// functions shall test whether c is a character of class digit in the current
// locale The c argument is an int, the value of which the application shall
// ensure is a character representable as an unsigned char or equal to the value
// of the macro EOF. If the argument has any other value, the behavior is
// undefined.
//     The isdigit() [CX] [Option Start]  and isdigit_l() [Option End] functions
//     shall return non-zero if c is a decimal digit; otherwise, they shall
//     return 0.

int e_isdigit(int c) {
  if (c >= 48 && c <= 57) {
    return 1;
  }
  return 0;
}
