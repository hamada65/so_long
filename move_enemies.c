/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:11:33 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/27 23:22:59 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	direction_0(t_mlx_data *mlx_data, t_enemy *data)
{
	if (mlx_data->map[data->pos_i][data->pos_j - 1] == '0')
	{
		mlx_data->map[data->pos_i][data->pos_j - 1] = 'X';
		mlx_data->map[data->pos_i][data->pos_j] = '0';
		data->pos_j--;
		data->direction = 0;
	}
	else if (mlx_data->map[data->pos_i][data->pos_j - 1] == 'P')
	{
		mlx_data->map[data->pos_i][data->pos_j - 1] = 'X';
		mlx_data->map[data->pos_i][data->pos_j] = '0';
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->floor.img, data->pos_j * 60, data->pos_i * 60);
		data->pos_j--;
		data->direction = -1;
		game_over(mlx_data, &data->pos_i, &data->pos_j);
	}
	else
		data->direction = 1;
}

void	direction_1(t_mlx_data *mlx_data, t_enemy *data)
{
	if (mlx_data->map[data->pos_i - 1][data->pos_j] == '0')
	{
		mlx_data->map[data->pos_i - 1][data->pos_j] = 'X';
		mlx_data->map[data->pos_i][data->pos_j] = '0';
		data->pos_i--;
		data->direction = 1;
	}
	else if (mlx_data->map[data->pos_i - 1][data->pos_j] == 'P')
	{
		mlx_data->map[data->pos_i - 1][data->pos_j] = 'X';
		mlx_data->map[data->pos_i][data->pos_j] = '0';
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->floor.img, data->pos_j * 60, data->pos_i * 60);
		data->pos_i--;
		data->direction = -1;
		game_over(mlx_data, &data->pos_i, &data->pos_j);
	}
	else
		data->direction = 2;
}

void	direction_2(t_mlx_data *mlx_data, t_enemy *data)
{
	if (mlx_data->map[data->pos_i][data->pos_j + 1] == '0')
	{
		mlx_data->map[data->pos_i][data->pos_j + 1] = 'X';
		mlx_data->map[data->pos_i][data->pos_j] = '0';
		data->pos_j++;
		data->direction = 2;
	}
	else if (mlx_data->map[data->pos_i][data->pos_j + 1] == 'P')
	{
		mlx_data->map[data->pos_i][data->pos_j + 1] = 'X';
		mlx_data->map[data->pos_i][data->pos_j] = '0';
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->floor.img, data->pos_j * 60, data->pos_i * 60);
		data->pos_j++;
		data->direction = -1;
		game_over(mlx_data, &data->pos_i, &data->pos_j);
	}
	else
		data->direction = 3;
}

void	direction_3(t_mlx_data *mlx_data, t_enemy *data)
{
	if (mlx_data->map[data->pos_i + 1][data->pos_j] == '0')
	{
		mlx_data->map[data->pos_i + 1][data->pos_j] = 'X';
		mlx_data->map[data->pos_i][data->pos_j] = '0';
		data->pos_i++;
		data->direction = 3;
	}
	else if (mlx_data->map[data->pos_i + 1][data->pos_j] == 'P')
	{
		mlx_data->map[data->pos_i + 1][data->pos_j] = 'X';
		mlx_data->map[data->pos_i][data->pos_j] = '0';
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->floor.img, data->pos_j * 60, data->pos_i * 60);
		data->pos_i++;
		data->direction = -1;
		game_over(mlx_data, &data->pos_i, &data->pos_j);
	}
	else
		data->direction = 0;
}
