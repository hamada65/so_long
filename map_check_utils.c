/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:38:11 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 20:03:05 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

void	get_start_pos(char **lines, int *i, int *j)
{
	int	k;
	int	l;

	k = 0;
	while (lines[k])
	{
		l = 0;
		while (lines[k][l])
		{
			if (lines[k][l] == 'P')
			{
				*i = k;
				*j = l;
				return ;
			}
			l++;
		}
		k++;
	}
}

char	**ft_strdup_array(char **lines)
{
	char	**duplicated_lines;
	int		i;

	i = 0;
	while (lines[i])
		i++;
	duplicated_lines = (char **)malloc(sizeof(char *) * (i + 1));
	if (!duplicated_lines)
		return (0);
	i = 0;
	while (lines[i])
	{
		duplicated_lines[i] = ft_strdup(lines[i]);
		i++;
	}
	duplicated_lines[i] = 0;
	return (duplicated_lines);
}

void	free_array(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

int	map_valid(char **lines)
{
	t_map_info	map;
	int			i;
	size_t		len;

	map.empty = map_calculate(lines, '0');
	map.collectible = map_calculate(lines, 'C');
	map.exit = map_calculate(lines, 'E');
	map.wall = map_calculate(lines, '1');
	map.starting = map_calculate(lines, 'P');
	i = 0;
	len = ft_strlen(lines[i]);
	while (lines[i])
	{
		if (len != ft_strlen(lines[i]))
			return (0);
		len = ft_strlen(lines[i]);
		i++;
	}
	if (map.exit != 1 || map.collectible < 1 || map.starting != 1)
		return (0);
	return (1);
}
