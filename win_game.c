/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:08:07 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/26 13:38:30 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void win_game(t_mlx_data *mlx_data, int *pos_i, int *pos_j)
{
    int i;
    int j;

    printf("You Win\n");
    i = mlx_data->map_size_x;
    while (i >= 0)
    {
        j = mlx_data->map_size_y;
        while (j >= 0)
        {
            mlx_pixel_put(mlx_data->mlx_ptr, mlx_data->mlx_window, i, j, 0xffffff);
            j--;
        }
        mlx_do_sync(mlx_data->mlx_ptr);
        // sleep(0.1);
        i--;
    }
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->win.img, ((mlx_data->map_size_x/60)-4)*30, ((mlx_data->map_size_y/60)-3)*30);
    mlx_do_sync(mlx_data->mlx_ptr);
    sleep(3);
    destroy_game(mlx_data);
}