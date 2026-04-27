#include "e_lib.h"

char *e_strndup(const char *s, size_t n) {
    size_t len = 0;
    while (len < n && s[len]) {
        len++;
    }
    char *new_str = e_malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
        new_str[i] = s[i];
    }
    new_str[len] = '\0';
    return new_str;
}