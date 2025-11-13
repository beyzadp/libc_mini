#include <constants.h>
#include <e_lib.h>

// testing printf function

int main(void) {
  e_printf("my name is %s and my surname is %s.\ni am %d years old. this is a "
           "charachter: %c, heres a hex: %X. \n",
           "beyza", "derin", 20, 'a', 3735928559);
}