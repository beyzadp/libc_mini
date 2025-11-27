#ifndef _E_LIBC_H
#define _E_LIBC_H

typedef unsigned long size_t;
typedef long ssize_t;

typedef long int intptr_t;

struct sockaddr;
typedef unsigned int socklen_t;
typedef int pid_t;

// for variadic functions
typedef __builtin_va_list va_list;
#define va_start __builtin_va_start
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg

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
void *sbrk(intptr_t increment);

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
int e_strncmp(const char *s1, const char *s2, size_t n);
int e_strlcat(char *dst, const char *src, size_t dstsize);
char *e_strrchr(const char *s, int c);
char *e_strdup(const char *s1);
int e_atoi(const char *nptr);
char *e_itoa(int n);
int e_tolower(int c);
int e_toupper(int c);

/**
 * e_strestr - Like strstr, but searches only within the first 'length' bytes of
 * 'haystack'. Returns pointer to first match, or NULL if not found within
 * length.
 */
char *e_strestr(const char *haystack, const char *needle, size_t length);

int e_printf(const char *format, ...);

void *e_malloc(size_t size);
void e_free(void *ptr);
#endif