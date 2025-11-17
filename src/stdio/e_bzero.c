#include <constants.h>
#include <e_lib.h>

void bzero(void *s, size_t n) { e_memset(s, 0, n); }