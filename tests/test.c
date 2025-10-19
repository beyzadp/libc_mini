// libc_mini/tests/test.c

#include <unistd.h>

int main(void) {
  const char msg[] = "Hello, syscall write!\n";
  write(1, msg,
        sizeof(msg) - 1); // sizeof(msg)-1 to exclude the null terminator
  return 0;
}
