/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:21:55 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/20 02:07:39 by mel-rhay         ###   ########.fr       */
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
	map.enimies = 0;
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
			else if (lines[i][j] == 'X')
				map.enimies++;
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

int 	map_walls(char **lines)
{
	int i;
	int j;
	int line_len;

	i = 0;
	line_len = ft_strlen(lines[i]);
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (i == 0 && lines[i][j] != '1')
				return (0);
			if (j == 0 && lines[i][j] != '1')
				return (0);
			if (j == (line_len - 1) && lines[i][j] != '1')
				return (0);
			if (!lines[i+1] && lines[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int map_lines(char **lines)
{
	int i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

void	get_start_pos(char **lines, int *i, int *j)
{
	int k;
	int l;

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

int		find_way_to_exit(char **lines, int i, int j)
{
	if (lines[i][j] == 'E')
		return (1);
	if (lines[i][j] == '1' || lines[i][j] == 'V' || lines[i][j] == 'X')
		return (0);
	lines[i][j] = 'V';
	if (find_way_to_exit(lines, i + 1, j))
		return (1);
	if (find_way_to_exit(lines, i - 1, j))
		return (1);
	if (find_way_to_exit(lines, i, j + 1))
		return (1);
	if (find_way_to_exit(lines, i, j - 1))
		return (1);
	return (0);
}

void	find_way_to_all_collectibles(char **lines, int i, int j, int required_coins, int *collected_coins)
{
	if (*collected_coins == required_coins)
		return ;
	if (lines[i][j] == 'P')
		lines[i][j] = '0';
	if (lines[i][j] == 'C')
		(*collected_coins)++;
	if (*collected_coins == required_coins)
		return ;
	if (lines[i][j] == '1' || lines[i][j] == 'V' || lines[i][j] == 'E' || lines[i][j] == 'X')
		return ;
	lines[i][j] = 'V';
	find_way_to_all_collectibles(lines, i + 1, j, required_coins, collected_coins);
	find_way_to_all_collectibles(lines, i - 1, j, required_coins, collected_coins);
	find_way_to_all_collectibles(lines, i, j + 1, required_coins, collected_coins);
	find_way_to_all_collectibles(lines, i, j - 1, required_coins, collected_coins);
}

char **ft_strdup_array(char **lines)
{
	char **duplicated_lines;
	int i;

	i = 0;
	while (lines[i])
		i++;
	duplicated_lines = (char **)malloc(sizeof(char *)*(i + 1));
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
	int i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

int		parse_map(char **lines)
{
	char **duplicated_lines;
	int num_lines;
	int i;
	int j;
	int collected_coins;
	int required_coins;

	required_coins = map_calculate(lines, 'C');
	duplicated_lines = ft_strdup_array(lines);
	num_lines = map_lines(duplicated_lines);
	get_start_pos(duplicated_lines, &i, &j);
	if (!find_way_to_exit(duplicated_lines, i, j))
	{
		free_array(duplicated_lines);
		return (0);
	}
	free_array(duplicated_lines);
	duplicated_lines = ft_strdup_array(lines);
	collected_coins = 0;
	find_way_to_all_collectibles(duplicated_lines, i, j, required_coins, &collected_coins);
	if (collected_coins != required_coins)
	{
		printf("collected_coins = %d, required = %d\n", collected_coins, required_coins);
		printf("Can't reach all collectibles i = %d, j = %d\n", i, j);
		free_array(duplicated_lines);
		return (0);
	}
	printf("collected_coins = %d, required = %d\n", collected_coins, required_coins);
	free_array(duplicated_lines);
	return (1);
}