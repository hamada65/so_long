/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:53:00 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/28 01:16:16 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calcul_map_size(char **map, int *size_x, int *size_y)
{
	int	i;
	int	j;

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

void	load_textures(t_mlx_data *mlx_data, char **map)
{
	int			i;
	int			j;
	static int	image = 0;
	static int	wait_coins = 0;
	static int	image_enemies = 0;
	static int	wait_enemies = 0;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
					mlx_data->wall.img, j * 60, i * 60);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
					mlx_data->floor.img, j * 60, i * 60);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
					mlx_data->coin[image].img, j * 60, i * 60);
			else if (map[i][j] == 'E')
			{
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
					mlx_data->exit_opened.img, j * 60, i * 60);
				mlx_data->exit_opened.pos_i = i;
				mlx_data->exit_opened.pos_j = j;
			}
			else if (map[i][j] == 'P')
			{
				if (mlx_data->direction)
					mlx_put_image_to_window(mlx_data->mlx_ptr,
						mlx_data->mlx_window,
						mlx_data->player_left[image_enemies].img, j * 60, i
						* 60);
				else
					mlx_put_image_to_window(mlx_data->mlx_ptr,
						mlx_data->mlx_window,
						mlx_data->player_right[image_enemies].img, j * 60, i
						* 60);
				mlx_data->player_pos_i = i;
				mlx_data->player_pos_j = j;
			}
			else if (map[i][j] == 'X')
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
					mlx_data->enemies[image_enemies].img, j * 60, i * 60);
			else if (map[i][j] == 'V')
			{
				mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
					mlx_data->exit.img, j * 60, i * 60);
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

void	check_pos(t_mlx_data *mlx_data)
{
	char	*tmp;
	int		*pos_i;
	int		*pos_j;

	mlx_clear_window(mlx_data->mlx_ptr, mlx_data->mlx_window);
	load_textures(mlx_data, mlx_data->map);
	mlx_data->moves++;
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
	mlx_data->map[*pos_i][*pos_j] = 'P';
	free(mlx_data->info);
	tmp = ft_itoa(mlx_data->moves);
	mlx_data->info = ft_strjoin("Player Moves : ", tmp);
	free(tmp);
}

int	render_map(t_mlx_data *mlx_data)
{
	static int	i = 0;

	if (i == 2000)
	{
		mlx_move_enemies(mlx_data);
		i = 0;
	}
	i++;
	mlx_string_put(mlx_data->mlx_ptr, mlx_data->mlx_window, 10,
		mlx_data->map_size_y + 15, 0xffffff, mlx_data->info);
	mlx_string_put(mlx_data->mlx_ptr, mlx_data->mlx_window, 10,
		mlx_data->map_size_y + 35, 0xffffff, mlx_data->info2);
	load_textures(mlx_data, mlx_data->map);
	return (0);
}

int	key_release(int keycode, t_mlx_data *mlx_data)
{
	int	*i;
	int	*j;

	i = &mlx_data->player_pos_i;
	j = &mlx_data->player_pos_j;
	if (keycode == 65307)
		destroy_game(mlx_data);
	else if (keycode == 119 || keycode == 65362) // w
	{
		if (mlx_data->map[(*i) - 1][*j] == '1' || mlx_data->map[(*i)
			- 1][*j] == 'E')
			return (keycode);
		mlx_data->map[(*i)][*j] = '0';
		(*i)--;
		check_pos(mlx_data);
	}
	else if (keycode == 115 || keycode == 65364) // s
	{
		if (mlx_data->map[(*i) + 1][*j] == '1' || mlx_data->map[(*i)
			+ 1][*j] == 'E')
			return (keycode);
		mlx_data->map[(*i)][*j] = '0';
		(*i)++;
		check_pos(mlx_data);
	}
	else if (keycode == 97 || keycode == 65361) // a
	{
		mlx_data->direction = 1;
		if (mlx_data->map[*i][(*j) - 1] == '1' || mlx_data->map[*i][(*j)
			- 1] == 'E')
			return (keycode);
		mlx_data->map[(*i)][*j] = '0';
		(*j)--;
		check_pos(mlx_data);
	}
	else if (keycode == 100 || keycode == 65363) // d
	{
		mlx_data->direction = 0;
		if (mlx_data->map[*i][(*j) + 1] == '1' || mlx_data->map[*i][(*j)
			+ 1] == 'E')
			return (keycode);
		mlx_data->map[(*i)][*j] = '0';
		(*j)++;
		check_pos(mlx_data);
	}
	else
		return (keycode);
	return (keycode);
}

int	map_calculate(char **s, char c)
{
	int	count;
	int	i;
	int	j;

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

void	load_game(char **map)
{
	t_mlx_data	mlx_data;
	char		*tmp;

	mlx_data.map = map;
	mlx_data.collected_coins = 0;
	mlx_data.moves = 0;
	mlx_data.direction = 0;
	mlx_data.required_coins = map_calculate(mlx_data.map, 'C');
	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
	{
		ft_printf("Error\n");
		destroy_game(&mlx_data);
	}
	calcul_map_size(mlx_data.map, &mlx_data.map_size_x, &mlx_data.map_size_y);
	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_ptr, mlx_data.map_size_x,
			mlx_data.map_size_y + 45, "so_long 1337");
	if (!mlx_data.mlx_window)
	{
		ft_printf("Error\n");
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
	mlx_loop_hook(mlx_data.mlx_ptr, &render_map, &mlx_data);
	mlx_hook(mlx_data.mlx_window, 2, 1L << 0, &key_release, &mlx_data);
	mlx_hook(mlx_data.mlx_window, 17, 0L, &destroy_game, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
}