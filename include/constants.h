// libc_mini/include/constants.h

#ifndef _CONSTANTS_H
#define _CONSTANTS_H

#define NULL ((void *)0)

#define SYS_READ 0
#define SYS_WRITE 1
#define SYS_OPEN 2
#define SYS_CLOSE 3
#define SYS_BRK 12
#define SYS_SOCKET 41
#define SYS_ACCEPT 43
#define SYS_BIND 49
#define SYS_LISTEN 50
#define SYS_FORK 57
#define SYS_EXIT 60
#define SYS_SETSOCKOPT 54
#define SYS_NANOSLEEP 35

#define O_RDONLY 0
#define O_WRONLY 1
#define O_RDWR 2
#define O_CREAT 64
#define O_EXCL 128
#define O_NOCTTY 256
#define O_TRUNC 512
#define O_APPEND 1024
#define O_NONBLOCK 2048
#define O_DSYNC 4096
#define O_SYNC 1052672

#define S_IRUSR 0400 // owner read
#define S_IWUSR 0200 // owner write
#define S_IXUSR 0100 // owner execute
#define S_IRGRP 0040 // group read
#define S_IWGRP 0020 // group write
#define S_IXGRP 0010 // group execute
#define S_IROTH 0004 // others read
#define S_IWOTH 0002 // others write
#define S_IXOTH 0001 // others execute

#endif