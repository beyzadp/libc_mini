#include <constants.h>
#include <syscall.h>

// char *strchr(const char *s, int c);

// The strchr() function shall locate the first occurrence of c (converted to a
// char) in the string pointed to by s. The terminating NUL character is
// considered to be part of the string.
//     Upon completion, strchr() shall return a pointer to the byte, or a null
//     pointer if the byte was not found.

char *strchr(const char *s, int c) {
  char ch = (char)c;
  while (*s) {
    if (*s == ch) {
      return (char *)s;
    }
    s++;
  }
  if (ch == '\0')
    return (char *)s;
  return NULL;
}
