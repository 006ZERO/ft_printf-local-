#include "ft_printf.h"

int ft_putnbr(int n) {
  long nb;
  int count;

  count = 0;
  nb = n;
  if (nb < 0) {
    count += ft_putchar('-');
    nb *= -1;
  }
  if (nb > 9) {
    count += ft_putnbr(nb / 10); // Accumulate counts from recursive calls
  }
  count += ft_putchar((nb % 10) + '0');

  return (count);
}
