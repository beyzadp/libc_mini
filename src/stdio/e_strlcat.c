#include <constants.h>
#include <e_lib.h>

// int e_strlcat(char *dst, const char *src, size_t dstsize);
// dst = abc\0
// src = kkk
// new dst = abckkk\0

// null terminates unless dstsize = 0 or no room

int e_strlcat(char *dst, const char *src, size_t dstsize) {
  char *tempdst = dst;
  while (*tempdst) {
    tempdst++;
  }
  size_t len_dst = e_strlen(dst);
  size_t len_src = e_strlen(src);

  size_t newsize = dstsize - 1;
  if (newsize - len_dst >= len_src) { // enough
    while (newsize) {
      *tempdst = *src;
      tempdst++;
      src++;
      newsize--;
    }
  } else {
    tempdst = dst + dstsize - 1;
    newsize = dstsize - len_dst - 1;
    *tempdst = '\0';
    tempdst--;
    while (newsize) {
      *tempdst = *(src + newsize - 1);
      tempdst--;
      newsize--;
    }
  }
  return (len_dst + len_src);
}
