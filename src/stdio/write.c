#include <syscall.h>
#include <unistd.h>

#define SYS_READ 0

ssize_t write(int fd, const void *buf, size_t count) {
  return (ssize_t)syscall3(SYS_READ, fd, (long)buf, count);
}