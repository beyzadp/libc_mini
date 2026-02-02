#include <constants.h>
#include <e_lib.h>
// int strncmp(const char *s1, const char *s2, size_t n);

// compares two string, maximum n characters, until null
// if same return 0

int e_strncmp(const char *s1, const char *s2, size_t n) {
    if (!s1 || !s2)
        return -1;

    while (n > 0) {
        if (*s1 == *s2) {
            if (*s1 == '\0') {
                return 0;
            }
            s1++;
            s2++;

        }

        else {
            return (unsigned char)*s1 - (unsigned char)*s2;
        }

        n--;
    }
    return 0;
}

// aaabdc
// aaabcd
