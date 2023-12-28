/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:07:38 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/28 23:03:39 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_str(t_mlx_data *mlx_data, int must_free)
{
	char	*tmp;

	if (must_free == 1)
	{
		free(mlx_data->info);
		free(mlx_data->info2);
	}
	tmp = ft_itoa(mlx_data->moves);
	mlx_data->info = ft_strjoin("Player Moves : ", tmp);
	free(tmp);
	tmp = ft_itoa(mlx_data->collected_coins);
	mlx_data->info2 = ft_strjoin("Collected Coins : ", tmp);
	free(tmp);
}

void	calcul_map_size(char **map, int *size_x, int *size_y)
{
	int	i;
	int	j;

	i = 0;
	*size_x = 0;
	*size_y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > *size_x)
			*size_x = j;
		i++;
	}
	*size_y = i;
	*size_x *= 60;
	*size_y *= 60;
}

void	data_init(t_mlx_data *mlx_data, char **map)
{
	mlx_data->map = map;
	mlx_data->collected_coins = 0;
	mlx_data->moves = 0;
	mlx_data->direction = 0;
	mlx_data->required_coins = map_calculate(mlx_data->map, 'C');
	calcul_map_size(mlx_data->map, &mlx_data->map_size_x,
		&mlx_data->map_size_y);
}

int	map_calculate(char **s, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
