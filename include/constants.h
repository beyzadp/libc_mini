// libc_mini/include/constants.h

#ifndef _CONSTANTS_H
#define _CONSTANTS_H

typedef unsigned long size_t;
typedef long ssize_t;

struct sockaddr;
typedef unsigned int socklen_t;
typedef int pid_t;

ssize_t write(int fd, const void *buf, size_t count);
ssize_t read(int fd, void *buf, size_t count);
int open(const char *path, int oflag, int mode);
int close(int fd);
int socket(int domain, int type, int protocol);
int accept(int socket, struct sockaddr *restrict address,
           socklen_t *restrict address_len);
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int listen(int sockfd, int backlog);
pid_t fork(void);
void exit(int status);
int setsockopt(int socket, int level, int option_name, const void *option_value,
               socklen_t option_len);

char *e_strchr(const char *s, int c);
size_t e_strlen(const char *s);
int e_isalpha(int c);
int e_isdigit(int c);
int e_isalnum(int c);
int e_isascii(int c);
int e_isprint(int c);

#define NULL ((void *)0);

#define SYS_READ 0
#define SYS_WRITE 1
#define SYS_OPEN 2
#define SYS_CLOSE 3
#define SYS_SOCKET 41
#define SYS_ACCEPT 43
#define SYS_BIND 49
#define SYS_LISTEN 50
#define SYS_FORK 57
#define SYS_EXIT 60
#define SYS_SETSOCKOPT 54

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

#endif