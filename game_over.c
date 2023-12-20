/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:05:47 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/19 17:32:28 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    game_over(t_mlx_data *mlx_data, int *pos_i, int *pos_j)
{
    int i;
    int j;

    printf("You Lose\n");
    printf("pos i = %d, pos j = %d\n", mlx_data->player.pos_i, mlx_data->player.pos_j);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->explosion.img, *pos_j * 60, *pos_i * 60);
    // mlx_string_put(mlx_data->mlx_ptr, mlx_data->mlx_window, (mlx_data->map_size_x)/2, (mlx_data->map_size_y)/2, 0xffffff, "You Loose");
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
        // sleep(0.1);
        i--;
    }
    printf("map size x = %d, y = %d\n", mlx_data->map_size_x/60, mlx_data->map_size_y/60);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->game_over.img, ((mlx_data->map_size_x/60)-4)*30, ((mlx_data->map_size_y/60)-3)*30);
    mlx_do_sync(mlx_data->mlx_ptr);
    sleep(3);
    mlx_destroy_display(mlx_data->mlx_ptr);
    exit(0);
}