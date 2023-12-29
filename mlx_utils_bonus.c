/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 03:53:00 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 21:04:47 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_textures(t_mlx_data *mlx_data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			put_textures(mlx_data, mlx_data->map, i, j);
			j++;
		}
		i++;
	}
}

void	check_pos(t_mlx_data *mlx_data)
{
	int	*pos_i;
	int	*pos_j;
	int	*exit_pos_i;
	int	*exit_pos_j;

	load_textures(mlx_data, mlx_data->map);
	mlx_data->moves++;
	pos_i = &mlx_data->player_pos_i;
	pos_j = &mlx_data->player_pos_j;
	exit_pos_i = &mlx_data->exit_opened.pos_i;
	exit_pos_j = &mlx_data->exit_opened.pos_j;
	if (mlx_data->map[*pos_i][*pos_j] == 'X')
		game_over(mlx_data, pos_i, pos_j);
	else if (mlx_data->map[*pos_i][*pos_j] == 'C')
	{
		mlx_data->map[*pos_i][*pos_j] = '0';
		mlx_data->collected_coins++;
	}
	else if (mlx_data->map[*pos_i][*pos_j] == 'V')
		win_game(mlx_data);
	if (mlx_data->collected_coins == mlx_data->required_coins)
		mlx_data->map[*exit_pos_i][*exit_pos_j] = 'V';
	mlx_data->map[*pos_i][*pos_j] = 'P';
	display_str(mlx_data, 1);
}

int	render_map(t_mlx_data *mlx_data)
{
	static long long	old_time;

	if (old_time == 0)
		old_time = current_time_in_milliseconds();
	if (current_time_in_milliseconds() - old_time >= MOVE_SPEED)
	{
		mlx_move_enemies(mlx_data);
		old_time = current_time_in_milliseconds();
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
		mlx_data->black_img.img, 0, mlx_data->map_size_y);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
		mlx_data->black_img.img, 60, mlx_data->map_size_y);
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window,
		mlx_data->black_img.img, 120, mlx_data->map_size_y);
	mlx_string_put(mlx_data->mlx_ptr, mlx_data->mlx_window, 10,
		mlx_data->map_size_y + 15, 0xffffff, mlx_data->info);
	mlx_string_put(mlx_data->mlx_ptr, mlx_data->mlx_window, 10,
		mlx_data->map_size_y + 35, 0xffffff, mlx_data->info2);
	load_textures(mlx_data, mlx_data->map);
	return (0);
}

void	load_game(char **map)
{
	t_mlx_data	mlx_data;

	data_init(&mlx_data, map);
	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
	{
		ft_printf("Error\n");
		destroy_game(&mlx_data);
	}
	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_ptr, mlx_data.map_size_x,
			mlx_data.map_size_y + 45, "so_long_bonus 1337");
	if (!mlx_data.mlx_window)
	{
		ft_printf("Error\n");
		destroy_game(&mlx_data);
	}
	load_images(&mlx_data);
	load_enemies(&mlx_data);
	load_textures(&mlx_data, mlx_data.map);
	display_str(&mlx_data, 0);
	mlx_loop_hook(mlx_data.mlx_ptr, &render_map, &mlx_data);
	mlx_hook(mlx_data.mlx_window, 2, 1L << 0, &key_release, &mlx_data);
	mlx_hook(mlx_data.mlx_window, 17, 0L, &destroy_game, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
}
