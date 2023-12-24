/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:27:55 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/23 03:59:29 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void go_right(t_mlx_data *mlx_data, int *i, int *j)
// {
//     printf("going right\n");
//     mlx_data->map[*i][*j - 1] = 'X';
//     mlx_data->map[*i][*j] = '0';
//     mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
//     mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->enemies.img, (*j - 1) * 60, *i * 60);
//     (*j)--;
//     sleep(1);
//     if (mlx_data->map[*i][*j - 1] == '0')
//         go_right(mlx_data, i, j);
// }

// void go_left(t_mlx_data *mlx_data, int *i, int *j)
// {
//     printf("go left\n");
//     mlx_data->map[*i][*j + 1] = 'X';
//     mlx_data->map[*i][*j] = '0';
//     mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
//     mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->enemies.img, (*j + 1) * 60, *i * 60);
//     (*j)++;
//     sleep(1);
//     if (mlx_data->map[*i][*j + 1] == '0')
//         go_left(mlx_data, i, j);
// }

// void    mlx_move_enemies(t_mlx_data *mlx_data, int *i, int *j)
// {
//     if (mlx_data->map[*i][*j - 1] == '0')
//         go_right(mlx_data, i, j);
//     else if (mlx_data->map[*i][*j + 1] == '0')
//         go_left(mlx_data, i, j);
//     mlx_move_enemies(mlx_data, i, j);
// }

// void    mlx_move_enemies_loop(t_mlx_data *mlx_data)
// {
//     int i;
//     int j;

//     i = 0;
//     while (mlx_data->map[i])
//     {
//         j = 0;
//         while (mlx_data->map[i][j])
//         {
//             if (mlx_data->map[i][j] == 'X')
//             {
//                 printf("found X at i = %d, j = %d\n", i, j);
//                 mlx_move_enemies(mlx_data, &i, &j);
//             }
//             j++;
//         }
//         i++;
//     }
// }

void   mlx_move_one_enemy(t_mlx_data *mlx_data, t_enemy *data)
{
    if (data->direction == 0)
    {
        if (mlx_data->map[data->pos_i][data->pos_j - 1] == '0')
        {
            // printf("going right\n");
            mlx_data->map[data->pos_i][data->pos_j - 1] = 'X';
            mlx_data->map[data->pos_i][data->pos_j] = '0';
            data->pos_j--;
            data->direction = 0;
        }
        else if (mlx_data->map[data->pos_i][data->pos_j - 1] == 'P')
        {
            mlx_data->map[data->pos_i][data->pos_j - 1] = 'X';
            mlx_data->map[data->pos_i][data->pos_j] = '0';
            mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, data->pos_j * 60, data->pos_i * 60);
            data->pos_j--;
            data->direction = -1;
            game_over(mlx_data, &data->pos_i, &data->pos_j);
        }
        else
            data->direction = 1;
    }
    if (data->direction == 1)
    {
        if (mlx_data->map[data->pos_i - 1][data->pos_j] == '0')
        {
            // printf("going up\n");
            mlx_data->map[data->pos_i - 1][data->pos_j] = 'X';
            mlx_data->map[data->pos_i][data->pos_j] = '0';
            data->pos_i--;
            data->direction = 1;
        }
        else if (mlx_data->map[data->pos_i - 1][data->pos_j] == 'P')
        {
            mlx_data->map[data->pos_i - 1][data->pos_j] = 'X';
            mlx_data->map[data->pos_i][data->pos_j] = '0';
            mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, data->pos_j * 60, data->pos_i * 60);
            data->pos_i--;
            data->direction = -1;
            game_over(mlx_data, &data->pos_i, &data->pos_j);
        }
        else
            data->direction = 2;
    }
    if (data->direction == 2)
    {
        if (mlx_data->map[data->pos_i][data->pos_j + 1] == '0')
        {
            // printf("go left\n");
            mlx_data->map[data->pos_i][data->pos_j + 1] = 'X';
            mlx_data->map[data->pos_i][data->pos_j] = '0';
            data->pos_j++;
            data->direction = 2;
        }
        else if (mlx_data->map[data->pos_i][data->pos_j + 1] == 'P')
        {
            mlx_data->map[data->pos_i][data->pos_j + 1] = 'X';
            mlx_data->map[data->pos_i][data->pos_j] = '0';
            mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, data->pos_j * 60, data->pos_i * 60);
            data->pos_j++;
            data->direction = -1;
            game_over(mlx_data, &data->pos_i, &data->pos_j);
        }
        else
            data->direction = 3;
    }
    if (data->direction == 3)
    {
        if (mlx_data->map[data->pos_i + 1][data->pos_j] == '0')
        {
            // printf("going down\n");
            mlx_data->map[data->pos_i + 1][data->pos_j] = 'X';
            mlx_data->map[data->pos_i][data->pos_j] = '0';
            data->pos_i++;
            data->direction = 3;
        }
        else if (mlx_data->map[data->pos_i + 1][data->pos_j] == 'P')
        {
            mlx_data->map[data->pos_i + 1][data->pos_j] = 'X';
            mlx_data->map[data->pos_i][data->pos_j] = '0';
            mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, data->pos_j * 60, data->pos_i * 60);
            data->pos_i++;
            data->direction = -1;
            game_over(mlx_data, &data->pos_i, &data->pos_j);
        }
        else
            data->direction = 0;
    }
}

void    mlx_move_enemies(t_mlx_data *mlx_data)
{
    t_enemy *tmp;
    int enemies_count;

    enemies_count = 0;
    tmp = mlx_data->enemies_info;
    while (tmp)
    {
        enemies_count++;
        printf("[%d] enemy at i = %d, j = %d\n", enemies_count, tmp->pos_i, tmp->pos_j);
        mlx_move_one_enemy(mlx_data, tmp);
        if (!tmp->next)
            printf("no next\n");
        tmp = tmp->next;
    }
}

void ft_enemyadd_back(t_enemy **lst, t_enemy *new)
{
    t_enemy *tmp;

    if (!(*lst))
        *lst = new;
    else
    {
        tmp = (*lst);
        while (tmp && tmp->next)
		    tmp = tmp->next;
        tmp->next = new;
    }
}

void load_enemies(t_mlx_data *mlx_data)
{
    int i;
    int j;
    t_enemy *new;
    int enemies_count;

    i = 0;
    enemies_count = 0;
    mlx_data->enemies_info = NULL;
    while (mlx_data->map[i])
    {
        j = 0;
        while (mlx_data->map[i][j])
        {
            if (mlx_data->map[i][j] == 'X')
            {
                new = (t_enemy *)malloc(sizeof(t_enemy));
                new->pos_i = i;
                new->pos_j = j;
                new->direction = 0;
                new->next = NULL;
                printf("enemy at i = %d, j = %d\n", new->pos_i, new->pos_j);
                ft_enemyadd_back(&mlx_data->enemies_info, new);
                enemies_count++;
            }
            j++;
        }
        i++;
    }
    printf("enemies_count = %d\n", enemies_count);
}