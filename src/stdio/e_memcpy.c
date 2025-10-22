#include <constants.h>
// void *memcpy(void *restrict s1, const void *restrict s2, size_t n);
//    The memcpy() function shall copy n bytes from the object pointed to by s2
//    into the object pointed to by s1. If copying takes place between objects
//    that overlap, the behavior is undefined.

// RETURN VALUE

//  The memcpy() function shall return s1; no return value is reserved to
//  indicate an error.

void *e_memcpy(void *restrict s1, const void *restrict s2, size_t n) {
  char *temps1 = (char *)s1;
  char *temps2 = (char *)s2;
  while (n) {

    *temps1 = *temps2;
    temps1++;
    temps2++;
    n--;
  }
  return s1;
}