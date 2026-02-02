#include <constants.h>
#include <e_lib.h>

char *e_strestr(const char *haystack, const char *needle, size_t length) {
    if (!needle[0])
        return (char *)haystack; // Needle is empty

    for (int i = 0; i < length; i++) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }
        if (!*n)
            return (char *)haystack; // Found entire needle
        haystack++;
    }
    return NULL; // Not found
}