/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:27:56 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 20:55:23 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_game(t_mlx_data *mlx_data)
{
	if (mlx_data->mlx_ptr)
	{
		if (mlx_data->mlx_window)
		{
			mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->mlx_window);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->wall.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->exit.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->floor.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->exit_opened.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->win.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->black_img.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->white_img.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->player_left.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->coin.img);
		}
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
	}
	free_array(mlx_data->map);
	exit(0);
	return (0);
}
