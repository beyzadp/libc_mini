#include <constants.h>
#include <e_lib.h>

// turns strings into integer

// The atoi() function converts the initial portion of the string
// pointed to by nptr to int.

// e_atoi: convert ASCII string to int (minimal, no error checking, skips
// whitespace)
int e_atoi(const char *nptr) {
  int ret = 0;
  int neg = 0;

  // skip whitespace
  while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n') {
    nptr++;
  }

  // handle sign
  if (*nptr == '-') {
    neg = 1;
    nptr++;
  } else if (*nptr == '+') {
    nptr++;
  }

  // process digits
  while (*nptr >= '0' && *nptr <= '9') {
    ret = ret * 10 + (*nptr - '0');
    nptr++;
  }

  if (neg) {
    ret = -ret;
  }
  return ret;
}