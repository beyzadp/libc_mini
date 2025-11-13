#include <constants.h>
#include <e_lib.h>

// turns strings into integer

// The atoi() function converts the initial portion of the string
// pointed to by nptr to int.

int e_atoi(const char *nptr) {
  unsigned long ret = 0;
  unsigned long n = 1;
  int neg = 0;

  // if its negative
  if (*nptr == '-') {
    neg = 1;
    nptr++;
  }

  while (*nptr) {
    ret += *nptr - '0';
    ret *= n;
    n *= 10;
    nptr++;
  }

  if (neg) {
    ret *= -1;
  }

  return ret;
  // while not:
  // substract '0'
  // multiply 10 = ret

  // if negative
  //-
}