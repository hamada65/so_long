/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:31:27 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/11/26 20:36:35 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base_void(unsigned long n, unsigned long baselen,
		char *base, int *count)
{
	if (n >= baselen)
	{
		ft_putnbr_base_void(n / baselen, baselen, base, count);
		ft_putchar(base[n % baselen], count);
	}
	else
		ft_putchar(base[n % baselen], count);
}

void	ft_putvoid(void *s, int *count)
{
	unsigned long	n;

	n = (unsigned long)s;
	if (n == 0)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		ft_putnbr_base_void(n, 16, "0123456789abcdef", count);
	}
}
