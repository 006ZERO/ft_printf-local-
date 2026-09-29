#include "ft_printf.h"
int ft_putstr(const char *s) {
  int i;

  i = 0;
  if (!s) {
    i += ft_putstr("(null)");
    return (i);
  }
  while (*s) {
    write(1, s++, 1);
    i++;
  }
  return (i);
}
