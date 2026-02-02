#include <constants.h>
#include <e_lib.h>

char *e_strstr(const char *haystack, const char *needle) {
    if (!needle[0])
        return (char *)haystack; // Needle is empty

    for (; *haystack; haystack++) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }
        if (!*n)
            return (char *)haystack; // Found entire needle
    }
    return NULL; // Not found
}