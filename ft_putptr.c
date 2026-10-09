/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabusalm <gabusalm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 12:46:04 by gabusalm          #+#    #+#             */
/*   Updated: 2026/09/30 12:46:05 by gabusalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int			i;
	uintptr_t	address;

	i = 0;
	if (!ptr)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	address = (uintptr_t)ptr;
	i += ft_putstr("0x");
	i += ft_puthex(address, false);
	return (i);
}
