/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:53:00 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/17 09:35:33 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void calcul_map_size(char **map, int *size_x, int *size_y)
{
	int i;
	int j;

	i = 0;
	*size_x = 0;
	*size_y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > *size_x)
			*size_x = j;
		i++;
	}
	*size_y = i;
	*size_x *= 60;
	*size_y *= 60;
}

void load_textures(t_mlx_data *mlx_data, char **map)
{
	int i;
	int j;

	mlx_data->wall.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/wall.xpm", &mlx_data->wall.width, &mlx_data->wall.height);
	mlx_data->floor.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/floor.xpm", &mlx_data->floor.width, &mlx_data->floor.height);
	mlx_data->player.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player.xpm", &mlx_data->player.width, &mlx_data->player.height);
	mlx_data->coin.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coin.xpm", &mlx_data->coin.width, &mlx_data->coin.height);
	mlx_data->exit_opened.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/exit_opened.xpm", &mlx_data->exit_opened.width, &mlx_data->exit_opened.height);
	mlx_data->exit.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/exit.xpm", &mlx_data->exit.width, &mlx_data->exit.height);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->wall.img, j * 60, i * 60);
				mlx_data->wall.pos_i = i;
				mlx_data->wall.pos_j = j;
			}
			else if (map[i][j] == '0')
			{
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, j * 60, i * 60);
				mlx_data->floor.pos_i = i;
				mlx_data->floor.pos_j = j;
			}
			else if (map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->coin.img, j * 60, i * 60);
				mlx_data->coin.pos_i = i;
				mlx_data->coin.pos_j = j;
			}
			else if (map[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->exit_opened.img, j * 60, i * 60);
				mlx_data->exit_opened.pos_i = i;
				mlx_data->exit_opened.pos_j = j;
			}
			else if (map[i][j] == 'P')
			{
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player.img, j * 60, i * 60);
				mlx_data->player.pos_i = i;
				mlx_data->player.pos_j = j;
			}
			j++;
		}
		i++;
	}
		
}

void update_door(t_mlx_data *mlx_data)
{
	int *i;
	int *j;

	i = &mlx_data->exit_opened.pos_i;
	j = &mlx_data->exit_opened.pos_j;
	mlx_data->exit.pos_i = mlx_data->exit_opened.pos_i;
	mlx_data->exit.pos_j = mlx_data->exit_opened.pos_j;
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->exit.img, *j * 60, *i * 60);
	mlx_data->map[*i][*j] = 'V';
}

void check_pos(t_mlx_data *mlx_data)
{
	int *pos_i;
	int *pos_j;

	mlx_data->moves++;
	pos_i = &mlx_data->player.pos_i;
	pos_j = &mlx_data->player.pos_j;
	if (mlx_data->map[*pos_i][*pos_j] == 'C')
	{
		mlx_data->map[*pos_i][*pos_j] = '0';
		mlx_data->collected_coins++;
	}
	else if (mlx_data->map[*pos_i][*pos_j] == 'V')
	{
		printf("You Won\n");
		mlx_destroy_display(mlx_data->mlx_ptr);
		exit(0);
		return ;
	}
	if (mlx_data->collected_coins == mlx_data->required_coins)
		update_door(mlx_data);
}

int key_release(int keycode, t_mlx_data *mlx_data)
{
	int *i;
	int *j;

	i = &mlx_data->player.pos_i;
	j = &mlx_data->player.pos_j;
	// printf("key released : %d\n", keycode);
	if (keycode == 119) // w
	{
		if (mlx_data->map[(*i)-1][*j] == '1' || mlx_data->map[(*i)-1][*j] == 'E')
			return (keycode);
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
		(*i)--;
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player.img, *j * 60, *i * 60);
	}
	else if (keycode == 115) // s
	{
		if (mlx_data->map[(*i)+1][*j] == '1' || mlx_data->map[(*i)+1][*j] == 'E')
			return (keycode);
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
		(*i)++;
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player.img, *j * 60, *i * 60);
	}
	else if (keycode == 97) // a
	{
		if (mlx_data->map[*i][(*j)-1] == '1' || mlx_data->map[*i][(*j)-1] == 'E')
			return (keycode);
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
		(*j)--;
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player.img, *j * 60, *i * 60);
	}
	else if (keycode == 100) // d
	{
		if (mlx_data->map[*i][(*j)+1] == '1' || mlx_data->map[*i][(*j)+1] == 'E')
			return (keycode);
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
		(*j)++;
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player.img, *j * 60, *i * 60);
	}
	else
		return (keycode);
	check_pos(mlx_data);
	printf("moves : %d, collected coins : %d, required_coind = %d\n", mlx_data->moves, mlx_data->collected_coins, mlx_data->required_coins);
	return (keycode);
}

int map_calculate(char **s, char c)
{
	int count;
	int i;
	int j;

	count = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void load_game(char **map)
{
	t_mlx_data mlx_data;
	int size_x;
	int size_y;

	mlx_data.map = map;
	mlx_data.collected_coins = 0;
	mlx_data.moves = 0;
	mlx_data.required_coins = map_calculate(mlx_data.map, 'C');
	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
	{
		printf("Error\n");
		return ;
	}
	calcul_map_size(mlx_data.map, &size_x, &size_y);
	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_ptr, size_x, size_y, "so_long 1337");
	if (!mlx_data.mlx_window)
	{
		printf("Error\n");
		return ;
	}
	load_textures(&mlx_data, mlx_data.map);
	mlx_key_hook(mlx_data.mlx_window, &key_release, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
}