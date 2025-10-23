#ifndef _E_LIBC_H
#define _E_LIBC_H

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
void *e_memset(void *s, int c, size_t n);
void *e_memcpy(void *restrict s1, const void *restrict s2, size_t n);
void *e_memmove(void *s1, const void *s2, size_t n);
size_t e_strlcpy(char *dst, const char *src, size_t size);
char *e_strstr(const char *haystack, const char *needle);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
char *e_strestr(const char *haystack, const char *needle, size_t length);

#endif