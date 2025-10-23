#include <constants.h>
#include <e_lib.h>

// void *memset(void *s, int c, size_t n);

//    The memset() function shall copy c (converted to an unsigned char) into
//    each of the first n bytes of the object pointed to by s.

// RETURN VALUE

//    The memset() function shall return s; no return value is reserved to
//    indicate an error.

//*s = abcdef
// c = k
// n = 3

// new *s = kkkdef

void *e_memset(void *s, int c, size_t n) {
  char *temp = (char *)s;
  while (n != 0) {
    *temp = (char)c;
    temp++;
    n--;
  }
  return s;
}
