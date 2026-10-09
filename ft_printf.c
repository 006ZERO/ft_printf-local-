/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 12:08:43 by gabusalm          #+#    #+#             */
/*   Updated: 2026/10/02 16:20:18 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, const char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), false));
	else if (c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), true));
	else if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%') + ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			count += ft_format(*format, &args);
		}
		else if (*format == '%')
		{
			va_end(args);
			return (-1);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
