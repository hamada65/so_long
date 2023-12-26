/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:53:00 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/26 14:22:05 by mel-rhay         ###   ########.fr       */
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

void load_images(t_mlx_data *mlx_data)
{
	mlx_data->wall.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/wall.xpm", &mlx_data->wall.width, &mlx_data->wall.height);
	mlx_data->floor.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/floor.xpm", &mlx_data->floor.width, &mlx_data->floor.height);
	mlx_data->player_left[0].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_left/0.xpm", &mlx_data->player_left[0].width, &mlx_data->player_left[0].height);
	mlx_data->player_left[1].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_left/1.xpm", &mlx_data->player_left[1].width, &mlx_data->player_left[1].height);
	mlx_data->player_left[2].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_left/2.xpm", &mlx_data->player_left[2].width, &mlx_data->player_left[2].height);
	mlx_data->player_left[3].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_left/3.xpm", &mlx_data->player_left[3].width, &mlx_data->player_left[3].height);
	mlx_data->player_left[4].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_left/4.xpm", &mlx_data->player_left[4].width, &mlx_data->player_left[4].height);
	mlx_data->player_left[5].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_left/5.xpm", &mlx_data->player_left[5].width, &mlx_data->player_left[5].height);
	mlx_data->player_right[0].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_right/0.xpm", &mlx_data->player_right[0].width, &mlx_data->player_right[0].height);
	mlx_data->player_right[1].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_right/1.xpm", &mlx_data->player_right[1].width, &mlx_data->player_right[1].height);
	mlx_data->player_right[2].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_right/2.xpm", &mlx_data->player_right[2].width, &mlx_data->player_right[2].height);
	mlx_data->player_right[3].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_right/3.xpm", &mlx_data->player_right[3].width, &mlx_data->player_right[3].height);
	mlx_data->player_right[4].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_right/4.xpm", &mlx_data->player_right[4].width, &mlx_data->player_right[4].height);
	mlx_data->player_right[5].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/player/frames_right/5.xpm", &mlx_data->player_right[5].width, &mlx_data->player_right[5].height);
	mlx_data->coin[0].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/0.xpm", &mlx_data->coin[0].width, &mlx_data->coin[0].height);
	mlx_data->coin[1].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/1.xpm", &mlx_data->coin[1].width, &mlx_data->coin[1].height);
	mlx_data->coin[2].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/2.xpm", &mlx_data->coin[2].width, &mlx_data->coin[2].height);
	mlx_data->coin[3].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/3.xpm", &mlx_data->coin[3].width, &mlx_data->coin[3].height);
	mlx_data->coin[4].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/4.xpm", &mlx_data->coin[4].width, &mlx_data->coin[4].height);
	mlx_data->coin[5].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/5.xpm", &mlx_data->coin[5].width, &mlx_data->coin[5].height);
	mlx_data->coin[6].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/6.xpm", &mlx_data->coin[6].width, &mlx_data->coin[6].height);
	mlx_data->coin[7].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/7.xpm", &mlx_data->coin[7].width, &mlx_data->coin[7].height);
	mlx_data->coin[8].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/8.xpm", &mlx_data->coin[8].width, &mlx_data->coin[8].height);
	mlx_data->coin[9].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/9.xpm", &mlx_data->coin[9].width, &mlx_data->coin[9].height);
	mlx_data->coin[10].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/10.xpm", &mlx_data->coin[10].width, &mlx_data->coin[10].height);
	mlx_data->coin[11].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/11.xpm", &mlx_data->coin[11].width, &mlx_data->coin[11].height);
	mlx_data->coin[12].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/12.xpm", &mlx_data->coin[12].width, &mlx_data->coin[12].height);
	mlx_data->coin[13].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/13.xpm", &mlx_data->coin[13].width, &mlx_data->coin[13].height);
	mlx_data->coin[14].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/14.xpm", &mlx_data->coin[14].width, &mlx_data->coin[14].height);
	mlx_data->coin[15].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/15.xpm", &mlx_data->coin[15].width, &mlx_data->coin[15].height);
	mlx_data->coin[16].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/16.xpm", &mlx_data->coin[16].width, &mlx_data->coin[16].height);
	mlx_data->coin[17].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/coins/frames/17.xpm", &mlx_data->coin[17].width, &mlx_data->coin[17].height);
	mlx_data->exit_opened.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/exit_opened.xpm", &mlx_data->exit_opened.width, &mlx_data->exit_opened.height);
	mlx_data->exit.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/exit.xpm", &mlx_data->exit.width, &mlx_data->exit.height);
	mlx_data->enemies[0].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/enemies/frames/0.xpm", &mlx_data->enemies[0].width, &mlx_data->enemies[0].height);
	mlx_data->enemies[1].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/enemies/frames/1.xpm", &mlx_data->enemies[1].width, &mlx_data->enemies[1].height);
	mlx_data->enemies[2].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/enemies/frames/2.xpm", &mlx_data->enemies[2].width, &mlx_data->enemies[2].height);
	mlx_data->enemies[3].img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/enemies/frames/3.xpm", &mlx_data->enemies[3].width, &mlx_data->enemies[3].height);
	mlx_data->explosion.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/explosion.xpm", &mlx_data->explosion.width, &mlx_data->explosion.height);
	mlx_data->game_over.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/game_over.xpm", &mlx_data->game_over.width, &mlx_data->game_over.height);
	mlx_data->win.img = mlx_xpm_file_to_image(mlx_data->mlx_ptr, "srcs/img/win.xpm", &mlx_data->win.width, &mlx_data->win.height);
}

void load_textures(t_mlx_data *mlx_data, char **map)
{
	int i;
	int j;
	static int image = 0;
	static int wait_coins = 0;
	static int image_enemies = 0;
	static int wait_enemies = 0;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->wall.img, j * 60, i * 60);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, j * 60, i * 60);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->coin[image].img, j * 60, i * 60);
			else if (map[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->exit_opened.img, j * 60, i * 60);
				mlx_data->exit_opened.pos_i = i;
				mlx_data->exit_opened.pos_j = j;
			}
			else if (map[i][j] == 'P')
			{
				if (mlx_data->direction)
					mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player_left[image_enemies].img, j * 60, i * 60);
				else
					mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player_right[image_enemies].img, j * 60, i * 60);
				mlx_data->player_pos_i = i;
				mlx_data->player_pos_j = j;
			}
			else if (map[i][j] == 'X')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->enemies[image_enemies].img, j * 60, i * 60);
			else if (map[i][j] == 'V')
			{
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->exit.img, j * 60, i * 60);
				mlx_data->exit.pos_i = i;
				mlx_data->exit.pos_j = j;
			}
			j++;
		}
		i++;
	}
	if (wait_coins == 70)
	{
		image++;
		if (image == 18)
			image = 0;
		wait_coins = 0;
	}
	if (wait_enemies == 400)
	{
		image_enemies++;
		if (image_enemies == 4)
			image_enemies = 0;
		wait_enemies = 0;
	}
	wait_enemies++;
	wait_coins++;
}

// void update_door(t_mlx_data *mlx_data)
// {
// 	int *i;
// 	int *j;

// 	i = &mlx_data->exit_opened.pos_i;
// 	j = &mlx_data->exit_opened.pos_j;
// 	// mlx_data->exit.pos_i = mlx_data->exit_opened.pos_i;
// 	// mlx_data->exit.pos_j = mlx_data->exit_opened.pos_j;
// 	// mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->exit.img, *j * 60, *i * 60);
// 	mlx_data->map[*i][*j] = 'V';
// }

void check_pos(t_mlx_data *mlx_data)
{
	char *tmp;

	mlx_clear_window(mlx_data->mlx_ptr, mlx_data->mlx_window);
	load_textures(mlx_data, mlx_data->map);
	mlx_data->moves++;
	int *pos_i;
	int *pos_j;
	pos_i = &mlx_data->player_pos_i;
	pos_j = &mlx_data->player_pos_j;
	if (mlx_data->map[*pos_i][*pos_j] == 'X')
	{
		game_over(mlx_data, pos_i, pos_j);
		return ;
	}
	else if (mlx_data->map[*pos_i][*pos_j] == 'C')
	{
		mlx_data->map[*pos_i][*pos_j] = '0';
		mlx_data->collected_coins++;
		free(mlx_data->info2);
		tmp = ft_itoa(mlx_data->collected_coins);
		mlx_data->info2 = ft_strjoin("Collected Coins : ", tmp);
		free(tmp);
	}
	else if (mlx_data->map[*pos_i][*pos_j] == 'V')
	{
		win_game(mlx_data, pos_i, pos_j);
		return ;
	}
	if (mlx_data->collected_coins == mlx_data->required_coins)
		mlx_data->map[mlx_data->exit_opened.pos_i][mlx_data->exit_opened.pos_j] = 'V';
		// update_door(mlx_data);
	mlx_data->map[*pos_i][*pos_j] = 'P';
	free(mlx_data->info);
	tmp = ft_itoa(mlx_data->moves);
	mlx_data->info = ft_strjoin("Player Moves : ", tmp);
	free(tmp);
	// printf("moves : %d, collected coins : %d, required_coind = %d\n", mlx_data->moves, mlx_data->collected_coins, mlx_data->required_coins);
}

int render_map(t_mlx_data *mlx_data)
{
	static int i = 0;

	if (i == 2000)
	{
		mlx_move_enemies(mlx_data);
		i = 0;
	} 
	i++;
	// mlx_string_put(mlx_data->mlx_ptr, mlx_data->mlx_window, 10, 25, 0xffffff, mlx_data->info);
	// mlx_string_put(mlx_data->mlx_ptr, mlx_data->mlx_window, 10, 50, 0xffffff, mlx_data->info2);
	mlx_string_put(mlx_data->mlx_ptr, mlx_data->mlx_window, 10, mlx_data->map_size_y + 15, 0xffffff, mlx_data->info);
	mlx_string_put(mlx_data->mlx_ptr, mlx_data->mlx_window, 10, mlx_data->map_size_y + 35, 0xffffff, mlx_data->info2);
	load_textures(mlx_data, mlx_data->map);
	//printf("render\n");
	// mlx_clear_window(mlx_data->mlx_ptr, mlx_data->mlx_window);
	return (0);
}

int key_release(int keycode, t_mlx_data *mlx_data)
{
	int *i;
	int *j;

	i = &mlx_data->player_pos_i;
	j = &mlx_data->player_pos_j;
	// printf("key released : %d\n", keycode);
	if (keycode == 119 || keycode == 65362) // w
	{
		if (mlx_data->map[(*i)-1][*j] == '1' || mlx_data->map[(*i)-1][*j] == 'E')
			return (keycode);
		// mlx_data->map[(*i)-1][*j] = 'P';
		mlx_data->map[(*i)][*j] = '0';
		(*i)--;
		check_pos(mlx_data);
		// mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
		// mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player_up.img, *j * 60, *i * 60);
	}
	else if (keycode == 115 || keycode == 65364) // s
	{
		if (mlx_data->map[(*i)+1][*j] == '1' || mlx_data->map[(*i)+1][*j] == 'E')
			
			return (keycode);
		// mlx_data->map[(*i)+1][*j] = 'P';
		mlx_data->map[(*i)][*j] = '0';
		// mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
		(*i)++;
		check_pos(mlx_data);
		// mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player.img, *j * 60, *i * 60);
	}
	else if (keycode == 97 || keycode == 65361) // a
	{
		mlx_data->direction = 1;
		if (mlx_data->map[*i][(*j)-1] == '1' || mlx_data->map[*i][(*j)-1] == 'E')
			return (keycode);
		// mlx_data->map[*i][(*j)-1] = 'P';
		mlx_data->map[(*i)][*j] = '0';
		// mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
		(*j)--;
		check_pos(mlx_data);
		// mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player_left.img, *j * 60, *i * 60);
	}
	else if (keycode == 100 || keycode == 65363) // d
	{
		mlx_data->direction = 0;
		if (mlx_data->map[*i][(*j)+1] == '1' || mlx_data->map[*i][(*j)+1] == 'E')
			return (keycode);
		// mlx_data->map[*i][(*j)+1] = 'P';
		mlx_data->map[(*i)][*j] = '0';
		// mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->floor.img, *j * 60, *i * 60);
		(*j)++;
		check_pos(mlx_data);
		// mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->player_right.img, *j * 60, *i * 60);
	}
	else
		return (keycode);
	// check_pos(mlx_data, i, j);
	// update_text_info(mlx_data);
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
	char *tmp;

	mlx_data.map = map;
	mlx_data.collected_coins = 0;
	mlx_data.moves = 0;
	mlx_data.direction = 0;
	mlx_data.required_coins = map_calculate(mlx_data.map, 'C');
	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
	{
		printf("Error\n");
		destroy_game(&mlx_data);
	}
	calcul_map_size(mlx_data.map, &mlx_data.map_size_x, &mlx_data.map_size_y);
	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_ptr, mlx_data.map_size_x, mlx_data.map_size_y + 45, "so_long 1337");
	if (!mlx_data.mlx_window)
	{
		printf("Error\n");
		destroy_game(&mlx_data);
	}
	load_images(&mlx_data);
	load_enemies(&mlx_data);
	load_textures(&mlx_data, mlx_data.map);
	tmp = ft_itoa(mlx_data.moves);
	mlx_data.info = ft_strjoin("Player Moves : ", tmp);
	free(tmp);
	tmp = ft_itoa(mlx_data.collected_coins);
	mlx_data.info2 = ft_strjoin("Collected Coins : ", tmp);
	free(tmp);
	// mlx_string_put(mlx_data.mlx_ptr, mlx_data.mlx_window, 60, 60, 16735835, "test");
	// mlx_move_enemies_loop(&mlx_data);
	// mlx_hook(mlx_data.mlx_window, 5, 0, &render_map, &mlx_data);
	mlx_loop_hook(mlx_data.mlx_ptr, &render_map, &mlx_data);
	mlx_hook(mlx_data.mlx_window, 2, 1L<<0, &key_release, &mlx_data);
	// mlx_key_hook(mlx_data.mlx_window, &key_release, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
}