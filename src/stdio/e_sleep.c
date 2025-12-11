// e_sleep.c
#include <constants.h>
#include <e_lib.h>
#include <syscall.h>

struct timespec {
  long tv_sec;  // seconds
  long tv_nsec; // nanoseconds
};

void e_sleep(unsigned int seconds) {
  struct timespec req;
  req.tv_sec = seconds;
  req.tv_nsec = 0;
  // __NR_nanosleep = 35 on x86_64
  syscall2(SYS_NANOSLEEP, (long)&req, 0);
}