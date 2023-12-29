/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:43:19 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/11/19 18:22:50 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr((nbr / 10), count);
		ft_putchar((nbr % 10) + '0', count);
	}
	else
		ft_putchar(nbr + '0', count);
}
