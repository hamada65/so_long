/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:08:07 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 20:56:30 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_white_background(t_mlx_data *mlx_data)
{
	int			i;
	int			j;

	i = (mlx_data->map_size_x / 60) - 1;
	while (i >= 0)
	{
		j = (mlx_data->map_size_y / 60);
		while (j >= 0)
		{
			mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
				mlx_data->white_img.img, i * 60, j * 60);
			j--;
		}
		i--;
	}
}

void	win_game(t_mlx_data *mlx_data)
{
	long	i;

	put_white_background(mlx_data);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
		mlx_data->win.img, ((mlx_data->map_size_x / 60) - 4) * 30,
		((mlx_data->map_size_y / 60) - 3) * 30);
	mlx_do_sync(mlx_data->mlx_ptr);
	i = 0;
	while (i++ < 6000000000)
		;
	destroy_game(mlx_data);
}
