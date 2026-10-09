/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 10:29:05 by gabusalm          #+#    #+#             */
/*   Updated: 2026/09/30 10:31:32 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>

int	ft_putstr(const char *str);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putchar(char c);
int	ft_puthex(uintptr_t n, bool uppercase);
int	ft_putptr(void *ptr);
int	ft_printf(const char *format, ...);

#endif
