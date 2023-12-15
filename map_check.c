/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:21:55 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/15 16:23:59 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_valid(char **lines)
{
	t_map_info map;
	int i;
	int j;
	int len;

	map.empty = 0;
	map.collectible = 0;
	map.exit = 0;
	map.wall = 0;
	map.starting = 0;
	i = 0;
	len = ft_strlen(lines[i]);
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] == '0')
				map.empty++;
			else if (lines[i][j] == '1')
				map.wall++;
			else if (lines[i][j] == 'C')
				map.collectible++;
			else if (lines[i][j] == 'E')
				map.exit++;
			else if (lines[i][j] == 'P')
				map.starting++;
			else
				return (0);
			j++;
		}
		if (len != ft_strlen(lines[i]))
				return (0);
		len = ft_strlen(lines[i]);
		i++;
	}
	if (map.exit != 1 || map.collectible < 1 || map.starting != 1)
		return (0);
	return 1;
}