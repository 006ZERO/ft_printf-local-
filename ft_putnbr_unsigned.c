/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 12:46:26 by gabusalm          #+#    #+#             */
/*   Updated: 2026/09/30 12:46:27 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_unsigned(n / 10);
	}
	count += ft_putchar((n % 10) + '0');
	return (count);
}
