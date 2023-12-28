/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:21:55 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/28 00:02:53 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_walls(char **lines)
{
	int	i;
	int	j;
	int	line_len;

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
			if (!lines[i + 1] && lines[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_way_to_exit(char **lines, int i, int j)
{
	if (lines[i][j] == 'E')
		return (1);
	if (lines[i][j] == '1' || lines[i][j] == 'V')
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

void	find_way_to_all_collectibles(char **lines, int i, int j,
		t_coin_info *coin_info)
{
	if (coin_info->collected_coins == coin_info->required_coins)
		return ;
	if (lines[i][j] == 'P')
		lines[i][j] = '0';
	if (lines[i][j] == 'C')
		(coin_info->collected_coins)++;
	if (coin_info->collected_coins == coin_info->required_coins)
		return ;
	if (lines[i][j] == '1' || lines[i][j] == 'V' || lines[i][j] == 'E')
		return ;
	lines[i][j] = 'V';
	find_way_to_all_collectibles(lines, i + 1, j, coin_info);
	find_way_to_all_collectibles(lines, i - 1, j, coin_info);
	find_way_to_all_collectibles(lines, i, j + 1, coin_info);
	find_way_to_all_collectibles(lines, i, j - 1, coin_info);
}

void	find_way_to_collectible(char **lines, int i, int j)
{
	char		**duplicated_lines;
	t_coin_info	coin_info;

	coin_info.required_coins = map_calculate(lines, 'C');
	coin_info.collected_coins = 0;
	duplicated_lines = ft_strdup_array(lines);
	find_way_to_all_collectibles(duplicated_lines, i, j, &coin_info);
	if (coin_info.collected_coins != coin_info.required_coins)
	{
		ft_printf("Error\nMap Invalid Can`t Reach All Collectible\n");
		ft_printf("Collected Coins :%d, Required Coins : %d\n",
			coin_info.collected_coins, coin_info.required_coins);
		free_array(duplicated_lines);
		exit(1);
	}
	free_array(duplicated_lines);
}

int	parse_map(char **lines)
{
	char	**duplicated_lines;
	int		num_lines;
	int		i;
	int		j;

	duplicated_lines = ft_strdup_array(lines);
	num_lines = map_lines(duplicated_lines);
	get_start_pos(duplicated_lines, &i, &j);
	if (!find_way_to_exit(duplicated_lines, i, j))
	{
		free_array(duplicated_lines);
		return (0);
	}
	free_array(duplicated_lines);
	find_way_to_collectible(lines, i, j);
	return (1);
}
