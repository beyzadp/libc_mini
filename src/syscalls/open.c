#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

//       int openat(int fd, const char *path, int oflag, ...);

// returns fd
// arg1: path to the file

int open(const char *path, int oflag, int mode) {
  return (int)syscall3(SYS_OPEN, (long)path, oflag, mode);
}