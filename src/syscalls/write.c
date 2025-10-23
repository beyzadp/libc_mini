#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

// arg1: fd where to write
// arg2: write from where
// arg3: how many ch

ssize_t write(int fd, const void *buf, size_t count) {
  return (ssize_t)syscall3(SYS_WRITE, fd, (long)buf, count);
}