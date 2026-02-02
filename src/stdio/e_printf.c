#include <constants.h>
#include <e_lib.h>

/*
1) The printf function will write each character of the intial string, one by
one, until it finds a %.

2) When it finds a %, it will look at the element in the next index/position. It
will find the character that will define the type of the first variable
argument.

3) Depending on what it finds, it will call a method that will display the
argument of the particular type at output. -> if there is a "s" after the %,
then you will need a function that displays strings. -> if there is a "d" after
the %, then you will need a function that displays numbers. etc.

4) Once the first variable argument has been written, you go back to step 1,
until the string is finished (aka, until you find a null character (\0)).

*/

int e_printf(const char *format, ...) {

    va_list ap;
    va_start(ap, format);
    int return_len = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'd') {
                int i = va_arg(ap, int);
                char *str = e_itoa(i); // Convert int i to string, base 10
                write(1, str, e_strlen(str)); // Write the string to output }
                return_len += e_strlen(str);
            } else if (*format == 's') {
                const char *s = va_arg(ap, const char *);
                while (*s) {
                    write(1, s, 1);
                    return_len += 1;
                    s++;
                }
            } else if (*format == 'c') {
                int character = va_arg(ap, int);
                char ch = (char)character;
                write(1, &ch, 1);
                return_len += 1;
            } else if (*format == '%') {
                write(1, "%", 1);
                return_len += 1;
            } else if (*format == 'x' || *format == 'X') {
                const int value = va_arg(ap, int);
                for (int i = 7; i >= 0; i--) {
                    const int nibble = (value >> (i * 4)) & 0xf;
                    write(1, &"0123456789abcdef"[nibble], 1);
                    return_len += 1;
                }
            } else if (*format == 'p') {
                void *ptr = va_arg(ap, void *);
                unsigned long val = (unsigned long)ptr;

                write(1, "0x", 2);

                // Print each hex digit by shifting and masking
                int started = 0;
                for (int i = (sizeof(unsigned long) * 2) - 1; i >= 0; i--) {
                    char digit = (val >> (i * 4)) & 0xf;
                    if (digit || started || i == 0) {
                        char c = "0123456789abcdef"[(int)digit];
                        write(1, &c, 1);
                        return_len += 1;

                        started = 1;
                    }
                }
            } else if (*format == 'l' && *(format + 1) == 'l' &&
                       *(format + 2) == 'u') {
                unsigned long long ull = va_arg(ap, unsigned long long);
                char *str = e_ulltoa(ull);
                write(1, str, e_strlen(str));
                return_len += e_strlen(str);
                format += 2;
            }

            else {
                char symbol = '%';
                write(1, &symbol, 1);
                return_len += 1;
                write(1, format, 1);
                return_len += 1;
            }

            // add %u
        } else {
            write(1, format, 1);
            return_len += 1;
        }
        format++;
    }
    return return_len;
}
