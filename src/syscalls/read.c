#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

// ssize_t read(size_t count;
//            int fd, void buf[count], size_t count);

// arg1: fd
// arg2: The buffer where the read data is to be stored.
// arg3: The number of bytes to be read from the file.

ssize_t read(int fd, void *buf, size_t count) {
  return (ssize_t)syscall3(SYS_READ, fd, (long)buf, count);
}