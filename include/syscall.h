#ifndef _SYSCALL_H
#define _SYSCALL_H

static inline long syscall(long number) {
  long ret;
  __asm__ volatile("mov %[num], %%rax\n\t"
                   "syscall"
                   : "=a"(ret)
                   : [num] "r"(number)
                   : "rcx", "r11");
  return ret;
}

static inline long syscall1(long number, long arg1) {
  long ret;
  __asm__ volatile("mov %[num], %%rax\n\t"
                   "mov %[a1], %%rdi\n\t"
                   "syscall"
                   : "=a"(ret)
                   : [num] "r"(number), [a1] "r"(arg1)
                   : "rcx", "r11", "rdi");
  return ret;
}

static inline long syscall2(long number, long arg1, long arg2) {
  long ret;
  __asm__ volatile("mov %[num], %%rax\n\t"
                   "mov %[a1], %%rdi\n\t"
                   "mov %[a2], %%rsi\n\t"
                   "syscall"
                   : "=a"(ret)
                   : [num] "r"(number), [a1] "r"(arg1), [a2] "r"(arg2)
                   : "rcx", "r11", "rdi", "rsi");
  return ret;
}

static inline long syscall3(long number, long arg1, long arg2, long arg3) {
  long ret;
  __asm__ volatile(
      "mov %[num], %%rax\n\t"
      "mov %[a1], %%rdi\n\t"
      "mov %[a2], %%rsi\n\t"
      "mov %[a3], %%rdx\n\t"
      "syscall"
      : "=a"(ret)
      : [num] "r"(number), [a1] "r"(arg1), [a2] "r"(arg2), [a3] "r"(arg3)
      : "rcx", "r11", "rdi", "rsi", "rdx");

  return ret;
}

#endif // _SYSCALL_H