/*
read 10 bytes from file+buffer_index into buffer
check if buffer has new line or eof until end of buffer
if no, write everything info line_buffer
buffer_index += 10
if yes, write everything until new line or eof into line_buffer
buffer_index += i + 1
and write whats in line buffer
clear line_buffer
return the char
*/

#include "constants.h"
#include "e_lib.h"

int buffer_clear(char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
    // move the rest of the buffer to the beginning of the buffer
    for (int i = size; i < 10; i++) {
        buffer[i - size] = buffer[i];
        buffer[i] = '\0';
    }
    return 0;
}

char *e_get_next_line(int fd) {

    int line_index = 0;

    char *line_buffer = e_malloc(sizeof(char) * 100);
    static char buffer[11];

    for (int i = 0; i < 100; i++)
        line_buffer[i] = '\0';

    while (1) {
        int bytes_read = read(fd, buffer, 10);

        if (buffer[0] == '\0') {
            int bytes_read = read(fd, buffer, 10);

            if (bytes_read <= 0) {
                if (line_index > 0) {
                    return line_buffer;
                }
                e_free(line_buffer);
                return NULL;
            }
        }

        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] == '\n' || buffer[i] == '\0') {
                // write everything until new line or eof into line_buffer

                for (int j = 0; j < i; j++) {
                    line_buffer[line_index + j] = buffer[j];
                }
                line_buffer[line_index + i] = '\0'; // Null-terminate the string

                // clear buffer until i and move the rest to the beginning of
                // buffer
                buffer_clear(buffer, i + 1);
                return line_buffer;
            }
        }
        for (int j = 0; j < 10; j++) {
            if (buffer[j] != '\0') {
                line_buffer[line_index] = buffer[j];
                line_index++;
            }
        }
        buffer_clear(buffer,
                     10); // Clear it so the next loop triggers read()
    }
}