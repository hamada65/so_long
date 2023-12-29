/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:25:43 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/11/19 18:24:02 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	if (!s)
		ft_putstr("(null)", count);
	else
	{
		while (*s)
		{
			ft_putchar(*s, count);
			s++;
		}
	}
}
