#include <constants.h>
#include <syscall.h>

// ssize_t read(size_t count;
//            int fd, void buf[count], size_t count);

#define SYS_READ 0

ssize_t read(int fd, void *buf, size_t count) {
  return (ssize_t)syscall3(SYS_READ, fd, (long)buf, count);
}