/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:59:23 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/11/19 00:30:44 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, unsigned int baselen, char *base, int *count)
{
	unsigned int	n;

	n = nbr;
	if (n >= baselen)
	{
		ft_putnbr_base(n / baselen, baselen, base, count);
		ft_putchar(base[n % baselen], count);
	}
	else
		ft_putchar(base[n % baselen], count);
}
