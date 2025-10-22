#include <constants.h>
#include <syscall.h>

// The strlen() function shall compute the number of bytes in the string to
// which s points, not including the terminating NUL character.
// The strnlen() function shall never examine more than maxlen bytes of the
// array pointed to by s.

// The strlen() function shall return the length of s; no return value shall be
// reserved to indicate an error.

size_t strlen(const char *s) {
  size_t length = 0;
  while (s[length] != '\0') {
    length++;
  }
  return length;
}
