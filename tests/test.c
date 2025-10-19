#include <constants.h>

// If your write wrapper uses the POSIX signature:
// ssize_t write(int fd, const void *buf, size_t count);
// and is defined in src/stdio/write.c

int main(void) {
  const char msg[] = "hello world\n";
  // Write to stdout (fd = 1)
  write(1, msg, sizeof(msg) - 1); // -1 to exclude the null terminator
  return 0;
}