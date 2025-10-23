#include <constants.h>
#include <e_lib.h>

// int isalpha(int c);

/*
    The isalpha()   and isalpha_l()  functions
shall test whether c is a character of class alpha in the current locale,
  or in the locale represented by locale,
respectively; see XBD Locale.

    The c argument is an int, the value of which the application shall ensure is
representable as an unsigned char or equal to the value of the macro EOF. If the
argument has any other value, the behavior is undefined.

   The behavior is undefined if the locale argument to
isalpha_l() is the special locale object LC_GLOBAL_LOCALE or is not a valid
locale object handle.

RETURN VALUE

    The isalpha()  and isalpha_l()   functions
shall return non-zero if c is an alphabetic character; otherwise, they shall
return 0.

    */

int e_isalpha(int c) {
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return 1; // non-zero
  }
  return 0;
}
