/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:04:38 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/28 00:57:41 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_frames(t_mlx_data *mlx_data, t_img_info *player, int count,
		int direction)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	while (i < count)
	{
		tmp = ft_itoa(i);
		if (direction == 0)
			tmp2 = ft_strjoin("srcs/img/player/frames_right/", tmp);
		else
			tmp2 = ft_strjoin("srcs/img/player/frames_left/", tmp);
		tmp3 = ft_strjoin(tmp2, ".xpm");
		player[i].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, tmp3,
				&player[i].width, &player[i].height);
		free(tmp);
		free(tmp2);
		free(tmp3);
		i++;
	}
}

void	load_coins_frames(t_mlx_data *mlx_data, t_img_info *coins, int count)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	while (i < count)
	{
		tmp = ft_itoa(i);
		tmp2 = ft_strjoin("srcs/img/coins/frames/", tmp);
		tmp3 = ft_strjoin(tmp2, ".xpm");
		coins[i].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, tmp3,
				&coins[i].width, &coins[i].height);
		free(tmp);
		free(tmp2);
		free(tmp3);
		i++;
	}
}

void	load_enemies_frames(t_mlx_data *mlx_data, t_img_info *enemies,
		int count)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	i = 0;
	while (i < count)
	{
		tmp = ft_itoa(i);
		tmp2 = ft_strjoin("srcs/img/enemies/frames/", tmp);
		tmp3 = ft_strjoin(tmp2, ".xpm");
		enemies[i].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, tmp3,
				&enemies[i].width, &enemies[i].height);
		free(tmp);
		free(tmp2);
		free(tmp3);
		i++;
	}
}

void	load_images(t_mlx_data *mlx_data)
{
	load_player_frames(mlx_data, mlx_data->player_left, 6, 1);
	load_player_frames(mlx_data, mlx_data->player_right, 6, 0);
	load_coins_frames(mlx_data, mlx_data->coin, 18);
	load_enemies_frames(mlx_data, mlx_data->enemies, 4);
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
	mlx_data->explosion.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/explosion.xpm", &mlx_data->explosion.width,
			&mlx_data->explosion.height);
	mlx_data->game_over.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/game_over.xpm", &mlx_data->game_over.width,
			&mlx_data->game_over.height);
	mlx_data->win.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
			"srcs/img/win.xpm", &mlx_data->win.width, &mlx_data->win.height);
}
