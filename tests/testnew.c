// libc_mini/tests/test.c

#include <constants.h>
#include <syscall.h>

int main(void) {
  const char *teststr = "hell, world!";
  char ch = 'o';

  char *result = strchr(teststr, ch);

  if (result) {
    // Output: "Found at position X\n"
    char msg[] = "Found at position ";
    write(1, msg, sizeof(msg) - 1);
    // Calculate position
    int pos = result - teststr;
    char num =
        '0' + pos; // Only works for single digit (0-9); for more, expand.
    write(1, &num, 1);
    write(1, "\n", 1);
  } else {
    char notfound[] = "Character not found\n";
    write(1, notfound, sizeof(notfound) - 1);
  }
  return 0;
}
