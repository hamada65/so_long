/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:27:56 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/26 14:33:13 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void destroy_images_array(t_mlx_data *mlx_data)
{
    int i;

    i = 0;
    while (i < 18)
    {
        // free(mlx_data->coin[i].img);
        mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->coin[i].img);
        i++;
    }
    i = 0;
    while (i < 6)
    {
        // free(mlx_data->player_left[i].img);
        // free(mlx_data->player_right[i].img);
        mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->player_left[i].img);
        mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->player_right[i].img);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        // free(mlx_data->enemies[i].img);
        mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->enemies[i].img);
        i++;
    }
}

void free_enemies(t_enemy **lst)
{
    t_enemy *tmp;

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


void destroy_game(t_mlx_data *mlx_data)
{
    // images Destroy
    mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->mlx_window);
    // free(mlx_data->wall.img);
    // free(mlx_data->exit.img);
    // free(mlx_data->exit_opened.img);
    // free(mlx_data->explosion.img);
    // free(mlx_data->game_over.img);
    // free(mlx_data->win.img);
	mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->wall.img);
    mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->exit.img);
    mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->floor.img);
    mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->exit_opened.img);
    mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->explosion.img);
    mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->game_over.img);
    mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->win.img);
    destroy_images_array(mlx_data);
    free_enemies(&mlx_data->enemies_info);
    free(mlx_data->info);
    free(mlx_data->info2);
    free_array(mlx_data->map);
    mlx_destroy_display(mlx_data->mlx_ptr);
    free(mlx_data->mlx_ptr);
    exit(0);
}