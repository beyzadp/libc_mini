#include <constants.h>
#include <e_lib.h>
// The isprint() [CX] [Option Start]  and isprint_l() [Option End]  functions
// shall return non-zero if c is a printable character; otherwise, they shall
// return 0.

int e_isprint(int c) {
  if (c >= 32 && c <= 126) {
    return 1;
  }
  return 0;
}
