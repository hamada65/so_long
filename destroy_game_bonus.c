/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:27:56 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 19:38:08 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_images_array(t_mlx_data *mlx_data)
{
	int	i;

	i = 0;
	while (i < 18)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->coin[i].img);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->player_left[i].img);
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->player_right[i].img);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->enemies[i].img);
		i++;
	}
}

void	free_enemies(t_enemy **lst)
{
	t_enemy	*tmp;

	if (lst && *lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
}

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
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->explosion.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->game_over.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->win.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->black_img.img);
			mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->white_img.img);
			destroy_images_array(mlx_data);
			free_enemies(&mlx_data->enemies_info);
			free(mlx_data->info);
			free(mlx_data->info2);
		}
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
	}
	free_array(mlx_data->map);
	exit(0);
	return (0);
}
