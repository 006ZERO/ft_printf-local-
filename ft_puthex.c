#include "ft_printf.h"

int ft_puthex(uintptr_t n, bool uppercase) {
  int i;
  char digit;
  const char *digits;

  i = 0;
  if (uppercase)
    digits = "0123456789ABCDEF";
  else
    digits = "0123456789abcdef";
  if (n >= 16) {
    i += ft_puthex(n / 16, uppercase);
  }
  digit = digits[n % 16];
  i += ft_putchar(digit);
  return (i);
}
