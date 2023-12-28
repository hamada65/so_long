/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:08:07 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/28 22:34:10 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_white_background(t_mlx_data *mlx_data)
{
	int			i;
	int			j;
	long long	old_time;

	old_time = current_time_in_milliseconds();
	i = (mlx_data->map_size_x / 60) - 1;
	while (i >= 0)
	{
		j = (mlx_data->map_size_y / 60);
		while (j >= 0)
		{
			mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
				mlx_data->white_img.img, i * 60, j * 60);
			j--;
			mlx_do_sync(mlx_data->mlx_ptr);
			while (current_time_in_milliseconds() - old_time < 2)
				;
			old_time = current_time_in_milliseconds();
		}
		i--;
	}
}

void	win_game(t_mlx_data *mlx_data, int *pos_i, int *pos_j)
{
	put_white_background(mlx_data);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
		mlx_data->win.img, ((mlx_data->map_size_x / 60) - 4) * 30,
		((mlx_data->map_size_y / 60) - 3) * 30);
	mlx_do_sync(mlx_data->mlx_ptr);
	sleep(3);
	destroy_game(mlx_data);
}
