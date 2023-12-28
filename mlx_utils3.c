/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:52:52 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/28 23:24:33 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frames_display(t_mlx_data *mlx_data, char type, int i, int j)
{
	static int	image;
	static int	image_enemies;

	if (type == 'C')
	{
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->coin[image].img, j * 60, i * 60);
	}
	else if (type == 'P')
	{
		if (mlx_data->direction)
			mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
				mlx_data->player_left[image_enemies].img, j * 60, i * 60);
		else
			mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
				mlx_data->player_right[image_enemies].img, j * 60, i * 60);
		mlx_data->player_pos_i = i;
		mlx_data->player_pos_j = j;
	}
	else if (type == 'X')
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->enemies[image_enemies].img, j * 60, i * 60);
	calculate_frames(&image, &image_enemies);
}

void	put_textures(t_mlx_data *mlx_data, char **map, int i, int j)
{
	if (map[i][j] == '1')
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->wall.img, j * 60, i * 60);
	else if (map[i][j] == '0')
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->floor.img, j * 60, i * 60);
	else if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'X')
		frames_display(mlx_data, map[i][j], i, j);
	else if (map[i][j] == 'E')
	{
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->exit_opened.img, j * 60, i * 60);
		mlx_data->exit_opened.pos_i = i;
		mlx_data->exit_opened.pos_j = j;
	}
	else if (map[i][j] == 'V')
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
			mlx_data->exit.img, j * 60, i * 60);
}
