#include <constants.h>
#include <e_lib.h>

/*
    strdup -- save a copy of a string
SYNOPSIS
    char *strdup(const char *s1);
DESCRIPTION
    The strdup() function allocates sufficient memory for a copy of the string
s1, does the copy, and returns a pointer to it. The pointer may subsequently be
used as an argument to the function free(3). If insufficient memory is
available, NULL is returned and errno is set to ENOMEM.*/

char *e_strdup(const char *s1) {

  char *dest;
  dest = (char *)e_malloc(e_strlen(s1) + 1);
  if (!dest) {
    return NULL;
  }
  int n = 0;
  char *tempdest;
  tempdest = dest;

  int len = e_strlen(s1);

  while (n <= len) {
    *tempdest = *(s1 + n);
    tempdest++;
    n++;
  }
  dest[n] = '\0';

  return dest;
}