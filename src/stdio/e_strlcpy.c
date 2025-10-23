#include <constants.h>
#include <e_lib.h>

// size_t strlcpy(char *dst, const char *src, size_t size);

/*
DESCRIPTION
    The strlcpy() function copy strings with the same input parameters and
output result as snprintf(3). It is designed to be safer, more consistent, and
less error prone replacement for the easily misused function strncpy(3)
    strlcpy() take the full size of the destination buffer and guarantee
NUL-termination if there is room. Note that room for the NUL should be included
in dstsize. Also note that strlcpy() only operate on true ''C'' strings. This
means that for strlcpy() src must be NUL-terminated. strlcpy() copies up to
dstsize - 1 characters from the string src to dst, NUL-terminating the result if
dstsize is not 0. If the src and dst strings overlap, the behavior is undefined.
RETURN VALUES
    The strlcpy() function return the total length of the strings it tried to
create. That means the length of src. If the return value is >= dstsize, the
output string has been truncated. It is the caller's responsibility to handle
this.
    */

size_t e_strlcpy(char *dst, const char *src, size_t size) {
  size_t src_len = e_strlen(src);

  if (size) {
    size_t to_copy = (src_len >= size) ? size - 1 : src_len;
    e_memcpy(dst, src, to_copy);
    dst[to_copy] = '\0';
  }

  return src_len;
}
