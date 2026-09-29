#include "ft_printf.h"
#include <stdarg.h>

static void ft_printf_helper(const char *p, int *count, va_list args) {
  if (*p == 'c')
    *count += ft_putchar(va_arg(args, int));
  else if (*p == 's')
    *count += ft_putstr(va_arg(args, const char *));
  else if (*p == 'p')
    *count += ft_putptr(va_arg(args, void *));
  else if (*p == 'd' || *p == 'i')
    *count += ft_putnbr(va_arg(args, int));
  else if (*p == 'u')
    *count += ft_putnbr_unsigned(va_arg(args, unsigned int));
  else if (*p == 'x')
    *count += ft_puthex(va_arg(args, unsigned int), false);
  else if (*p == 'X')
    *count += ft_puthex(va_arg(args, unsigned int), true);
  else if (*p == '%')
    *count += ft_putchar('%');
  else {
    *count += ft_putchar('%');
    *count += ft_putchar(*p);
  }
}

int ft_printf(const char *format, ...) {
  int count;
  const char *p;
  va_list args;

  if (!format)
    return (-1);
  count = 0;
  p = format;
  va_start(args, format);
  while (*p) {
    if (*p == '%') {
      p++;
      if (*p) {
        ft_printf_helper(p, &count, args);
        p++;
      } else {
        va_end(args);
        return (-1);
      }
    } else {
      count += ft_putchar(*p);
      p++;
    }
  }
  va_end(args);
  return (count);
}
