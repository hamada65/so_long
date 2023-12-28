/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:27:55 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/27 23:25:45 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_move_one_enemy(t_mlx_data *mlx_data, t_enemy *data)
{
	if (data->direction == 0)
		direction_0(mlx_data, data);
	if (data->direction == 1)
		direction_1(mlx_data, data);
	if (data->direction == 2)
		direction_2(mlx_data, data);
	if (data->direction == 3)
		direction_3(mlx_data, data);
}

void	mlx_move_enemies(t_mlx_data *mlx_data)
{
	t_enemy	*tmp;

	tmp = mlx_data->enemies_info;
	while (tmp)
	{
		mlx_move_one_enemy(mlx_data, tmp);
		tmp = tmp->next;
	}
}

void	ft_enemyadd_back(t_enemy **lst, t_enemy *new)
{
	t_enemy	*tmp;

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

void	load_enemies(t_mlx_data *mlx_data)
{
	int		i;
	int		j;
	t_enemy	*new;

	i = 0;
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
				ft_enemyadd_back(&mlx_data->enemies_info, new);
			}
			j++;
		}
		i++;
	}
}
