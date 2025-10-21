// libc_mini/tests/test.c

#include <constants.h>
#include <syscall.h>

#define BUF_SIZE 128

int main(void) {
  int fd = 0;
  char buf[BUF_SIZE];
  int n = read(fd, buf,
               BUF_SIZE - 1); // sizeof(msg)-1 to exclude the null terminator

  open(buf, O_RDONLY, 0);
  write(1, buf, n); // write to stdout (fd 1)
  close(fd);
  return 0;
}
