#include <constants.h>
#include <syscall.h>

#define SYS_WRITE 1

ssize_t write(int fd, const void *buf, size_t count) {
  return (ssize_t)syscall3(SYS_WRITE, fd, (long)buf, count);
}