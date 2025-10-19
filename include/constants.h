// libc_mini/include/unistd.h

#ifndef _UNISTD_H
#define _UNISTD_H

#include <stddef.h>
#include <sys/types.h> // ssize_t type

#ifdef __cplusplus
extern "C" {
#endif

ssize_t write(int fd, const void *buf, size_t count);
ssize_t read(int fd, void *buf, size_t count);
int open(const char *path, int oflag, int mode);

// Temporary file open flags
#define O_RDONLY 0   // Open for reading only
#define O_WRONLY 1   // Open for writing only
#define O_RDWR 2     // Open for reading and writing
#define O_CREAT 0100 // Create file if it does not exist

#define S_IRUSR 0400 // owner read
#define S_IWUSR 0200 // owner write
#define S_IXUSR 0100 // owner execute
#define S_IRGRP 0040 // group read
#define S_IWGRP 0020 // group write
#define S_IXGRP 0010 // group execute
#define S_IROTH 0004 // others read
#define S_IWOTH 0002 // others write
#define S_IXOTH 0001 // others execute

#ifdef __cplusplus
}
#endif

#endif // _UNISTD_H