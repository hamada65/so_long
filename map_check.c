/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:21:55 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/14 21:22:00 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int line_lenghnt(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

int map_valid(int fd)
{
	t_map_info map;
	char *str;
	int i;
	int len;

	map.empty = 0;
	map.collectible = 0;
	map.exit = 0;
	map.wall = 0;
	map.starting = 0;
	str = get_next_line(fd);
	if (!str)
		return (0);
	len = line_lenghnt(str);
	while (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == '0')
				map.empty++;
			else if (str[i] == '1')
				map.wall++;
			else if (str[i] == 'C')
				map.collectible++;
			else if (str[i] == 'E')
				map.exit++;
			else if (str[i] == 'P')
				map.starting++;
			else if (str[i] != '\n')
				return (0);
			i++;
		}
		if (len != line_lenghnt(str))
				return (0);
		len = line_lenghnt(str);
		str = get_next_line(fd);
	}
	if (map.exit != 1 || map.collectible < 1 || map.starting != 1)
		return (0);
	return 1;
}