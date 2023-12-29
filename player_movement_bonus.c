/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:34:35 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 19:39:09 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	go_up(t_mlx_data *mlx_data, int *i, int *j)
{
	if (mlx_data->map[(*i) - 1][*j] == '1' || mlx_data->map[(*i)
		- 1][*j] == 'E')
		return ;
	mlx_data->map[(*i)][*j] = '0';
	(*i)--;
	check_pos(mlx_data);
}

void	go_down(t_mlx_data *mlx_data, int *i, int *j)
{
	if (mlx_data->map[(*i) + 1][*j] == '1' || mlx_data->map[(*i)
		+ 1][*j] == 'E')
		return ;
	mlx_data->map[(*i)][*j] = '0';
	(*i)++;
	check_pos(mlx_data);
}

void	go_left(t_mlx_data *mlx_data, int *i, int *j)
{
	mlx_data->direction = 1;
	if (mlx_data->map[*i][(*j) - 1] == '1' || mlx_data->map[*i][(*j)
		- 1] == 'E')
		return ;
	mlx_data->map[(*i)][*j] = '0';
	(*j)--;
	check_pos(mlx_data);
}

void	go_right(t_mlx_data *mlx_data, int *i, int *j)
{
	mlx_data->direction = 0;
	if (mlx_data->map[*i][(*j) + 1] == '1' || mlx_data->map[*i][(*j)
		+ 1] == 'E')
		return ;
	mlx_data->map[(*i)][*j] = '0';
	(*j)++;
	check_pos(mlx_data);
}

int	key_release(int keycode, t_mlx_data *mlx_data)
{
	int	*i;
	int	*j;

	i = &mlx_data->player_pos_i;
	j = &mlx_data->player_pos_j;
	if (keycode == 65307)
		destroy_game(mlx_data);
	else if (keycode == 119 || keycode == 65362)
		go_up(mlx_data, i, j);
	else if (keycode == 115 || keycode == 65364)
		go_down(mlx_data, i, j);
	else if (keycode == 97 || keycode == 65361)
		go_left(mlx_data, i, j);
	else if (keycode == 100 || keycode == 65363)
		go_right(mlx_data, i, j);
	return (keycode);
}
