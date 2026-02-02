#include <constants.h>
#include <e_lib.h>
// str = "123.123,123"
// delim=".,"
// str = "123\0123\0123"

char *e_strtok(char *str, const char *delim) {
    static char *next = NULL;
    // Step 1: Initial call or continuation?
    if (str != NULL) {
        next = str;
    }
    if (next == NULL) {
        return NULL;
    }

    // Step 2: Skip any delimiter characters at the beginning
    char *start = next;
    while (*start && e_strchr(delim, *start)) {
        start++;
    }
    if (*start == '\0') {
        next = NULL;
        return NULL;
    }

    // Step 3: Find end of token
    char *end = start;
    while (*end && !e_strchr(delim, *end)) {
        end++;
    }

    // Step 4: If end is delimiter, overwrite it with '\0' and update 'next'
    if (*end) {
        *end = '\0';
        next = end + 1;
    } else {
        // No more tokens
        next = NULL;
    }

    // Step 5: Return pointer to token
    return start;
}