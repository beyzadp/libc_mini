#include <constants.h>
#include <syscall.h>

// char *strchr(const char *s, int c);

char *strchr(const char *s, int c) {
  while (*s) {
    if (*s == (char)c) {
      return (char *)s;
    }
    s++;
  }
  if ((char)c == '\0') // Special case: search for '\0'
    return (char *)s;  // Return pointer to end of string
  return NULL;         // If not found, return NULL
}