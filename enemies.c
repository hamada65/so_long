/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:27:55 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/19 18:46:40 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void go_right(t_mlx_data *mlx_data, int *i, int *j)
{
    printf("going right\n");
    mlx_data->map[*i][*j - 1] = 'X';
    mlx_data->map[*i][*j] = '0';
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->enemies.img, (*j - 1) * 60, *i * 60);
    (*j)--;
    sleep(1);
    if (mlx_data->map[*i][*j - 1] == '0')
        go_right(mlx_data, i, j);
}

void go_left(t_mlx_data *mlx_data, int *i, int *j)
{
    printf("go left\n");
    mlx_data->map[*i][*j + 1] = 'X';
    mlx_data->map[*i][*j] = '0';
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
    mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->enemies.img, (*j + 1) * 60, *i * 60);
    (*j)++;
    sleep(1);
    if (mlx_data->map[*i][*j + 1] == '0')
        go_left(mlx_data, i, j);
}

void    mlx_move_enemies(t_mlx_data *mlx_data, int *i, int *j)
{
    if (mlx_data->map[*i][*j - 1] == '0')
        go_right(mlx_data, i, j);
    else if (mlx_data->map[*i][*j + 1] == '0')
        go_left(mlx_data, i, j);
    mlx_move_enemies(mlx_data, i, j);
}

void    mlx_move_enemies_loop(t_mlx_data *mlx_data)
{
    int i;
    int j;

    i = 0;
    while (mlx_data->map[i])
    {
        j = 0;
        while (mlx_data->map[i][j])
        {
            if (mlx_data->map[i][j] == 'X')
            {
                printf("found X at i = %d, j = %d\n", i, j);
                mlx_move_enemies(mlx_data, &i, &j);
            }
            j++;
        }
        i++;
    }
}