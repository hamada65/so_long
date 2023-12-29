/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:52:51 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/11/19 18:24:41 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unbr(int n, int *count)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
	{
		ft_unbr((nbr / 10), count);
		ft_putchar((nbr % 10) + '0', count);
	}
	else
		ft_putchar(nbr + '0', count);
}
