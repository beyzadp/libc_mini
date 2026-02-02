#include <constants.h>
#include <e_lib.h>

char *e_itoa(int n) {
    static char buf[12]; // Enough for 32-bit ints: -2147483648\0
    int i = 0;
    int is_neg = 0;

    // Handle zero
    if (n == 0) {
        buf[i++] = '0';
        buf[i] = '\0';
        return buf;
    }

    // Handle negative numbers
    if (n < 0) {
        is_neg = 1;
        unsigned int num = (unsigned int)(-(n + 1)) + 1;
        n = num;
    }

    int num = n > 0 ? n : -n;

    // Build digits in reverse
    while (num != 0) {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    if (is_neg)
        buf[i++] = '-';

    buf[i] = '\0';

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char tmp = buf[start];
        buf[start] = buf[end];
        buf[end] = tmp;
        start++;
        end--;
    }

    return buf;
}