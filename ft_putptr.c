#include "ft_printf.h"

int ft_putptr(void *ptr) {
  int i;
  uintptr_t address;

  i = 0;
  if (!ptr) {
    i += ft_putstr("(nil)");
    return (i);
  }
  address = (uintptr_t)ptr;
  i += ft_putstr("0x");
  i += ft_puthex(address, false);
  return (i);
}
