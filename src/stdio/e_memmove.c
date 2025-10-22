#include <constants.h>

// void *memmove(void *s1, const void *s2, size_t n);

// The memmove() function shall copy n bytes from the object pointed to by s2
// into the object pointed to by s1.
// Copying takes place as if the n bytes from
// the object pointed to by s2 are first copied into a temporary array of n
// bytes that does not overlap the objects pointed to by s1 and s2, and then the
// n bytes from the temporary array are copied into the object pointed to by s1.

// RETURN VALUE

//    The memmove() function shall return s1; no return value is reserved to
//    indicate an error.

// ex:
//     char str[] = "123456789";
//     memmove(str + 3, str, 5);
// Result: 123123459

void *e_memmove(void *s1, const void *s2, size_t n) {
  char *dest = (char *)s1;
  const char *src =
      (char *)s2; // added const for not accidentally change source.

  if (dest < src) {
    while (n) {
      *dest++ = *src++;
      n--;
    }
  } else if (dest > src) {
    // Overlap: copy backward to avoid early overwrite
    dest += n;
    src += n;
    while (n--) {
      *(--dest) = *(--src);
    }
  }

  return s1;
}