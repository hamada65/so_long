/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:05:47 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/27 23:27:07 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_mlx_data *mlx_data, int *pos_i, int *pos_j)
{
	int	i;
	int	j;

	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
		mlx_data->explosion.img, *pos_j * 60, *pos_i * 60);
	mlx_do_sync(mlx_data->mlx_ptr);
	sleep(1);
	i = mlx_data->map_size_x;
	while (i >= 0)
	{
		j = mlx_data->map_size_y;
		while (j >= 0)
		{
			mlx_pixel_put(mlx_data->mlx_ptr, mlx_data->mlx_window, i, j, 0);
			j--;
		}
		mlx_do_sync(mlx_data->mlx_ptr);
		i--;
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
		mlx_data->game_over.img, ((mlx_data->map_size_x / 60) - 4) * 30,
		((mlx_data->map_size_y / 60) - 3) * 30);
	mlx_do_sync(mlx_data->mlx_ptr);
	sleep(3);
	destroy_game(mlx_data);
}
