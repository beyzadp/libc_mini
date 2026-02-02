#include <constants.h>
#include <e_lib.h>

//**e_strrchr** - Find last occurrence of a character.

/*

char *e_strchr(const char *s, int c) {
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
}*/

/*
NAME
    strrchr -- locate character in string
SYNOPSIS
    char *strrchr(const char *s, int c);
DESCRIPTION
    The strrchr() function is identical to strchr(), except it locates the last
occurence of c. RETURN VALUES The function strrchr() returns a pointer to the
located character, or NULL if the character does not appear in the string.
*/

char *e_strrchr(const char *s, int c) {
    char ch = (char)c;
    size_t s_len = e_strlen(s);
    while (s_len + 1) {
        if (*(s + s_len) == ch) {
            return (char *)(s + s_len);
        }
        s_len--;
    }
    if (ch == '\0')
        return (char *)s;

    return NULL;
}