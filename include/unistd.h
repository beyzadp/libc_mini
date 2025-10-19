// libc_mini/include/unistd.h

#ifndef _UNISTD_H
#define _UNISTD_H

#include <stddef.h>
#include <sys/types.h> // ssize_t type

#ifdef __cplusplus
extern "C" {
#endif

ssize_t write(int fd, const void *buf, size_t count);

#ifdef __cplusplus
}
#endif

#endif // _UNISTD_H