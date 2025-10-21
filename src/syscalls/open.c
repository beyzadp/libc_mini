#include <constants.h>
#include <syscall.h>

//       int openat(int fd, const char *path, int oflag, ...);

int open(const char *path, int oflag, int mode) {
  return (int)syscall3(SYS_OPEN, (long)path, oflag, mode);
}