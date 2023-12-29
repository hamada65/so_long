/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:04:38 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 20:57:59 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_mlx_data *mlx_data)
{
	mlx_data->coin.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/coins/frames/4.xpm", &mlx_data->coin.width,
			&mlx_data->coin.height);
	mlx_data->player_left.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/player/frames_right/0.xpm", &mlx_data->player_left.width,
			&mlx_data->player_left.height);
	mlx_data->wall.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/wall.xpm", &mlx_data->wall.width, &mlx_data->wall.height);
	mlx_data->floor.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/floor.xpm", &mlx_data->floor.width,
			&mlx_data->floor.height);
	mlx_data->exit_opened.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/exit_opened.xpm", &mlx_data->exit_opened.width,
			&mlx_data->exit_opened.height);
	mlx_data->exit.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/exit.xpm", &mlx_data->exit.width, &mlx_data->exit.height);
	mlx_data->win.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/win.xpm", &mlx_data->win.width, &mlx_data->win.height);
	mlx_data->black_img.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/black.xpm", &mlx_data->black_img.width,
			&mlx_data->black_img.height);
	mlx_data->white_img.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/white.xpm", &mlx_data->white_img.width,
			&mlx_data->white_img.height);
}
