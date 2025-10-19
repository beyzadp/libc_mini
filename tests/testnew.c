// libc_mini/tests/test.c

#include <constants.h>
#include <syscall.h>

#define BUF_SIZE 128

int main(void) {
  char *file = "/home/beyza/tuba";
  char buf[BUF_SIZE];

  int fd = open(file, O_RDONLY, 0);
  int n = read(fd, buf,
               BUF_SIZE - 1); // sizeof(msg)-1 to exclude the null terminator
  write(1, buf, n);           // write to stdout (fd 1)
  return 0;
}
