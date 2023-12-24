/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:26 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/23 22:23:01 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "srcs/get_next_line/get_next_line.h"
#include "srcs/libft/libft.h"
#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
# include <fcntl.h>
#include <string.h>
# include <unistd.h>

typedef struct img_info
{
	int width;
	int height;
	int pos_i;
	int pos_j;
	void *img;
}	t_img_info;

typedef struct s_enemy
{
	int pos_i;
	int pos_j;
	int direction;
	struct s_enemy *next;
}	t_enemy;

typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *mlx_window;
	char **map;
	t_enemy *enemies_info;
	int map_size_x;
	int map_size_y;
	t_img_info wall;
	t_img_info floor;
	t_img_info coin[18];
	t_img_info player_left[6];
	t_img_info player_right[6];
	t_img_info exit;
	t_img_info exit_opened;
	t_img_info enemies[4];
	t_img_info explosion;
	t_img_info game_over;
	t_img_info win;
	int required_coins;
	int collected_coins;
	int moves;
	char *info;
	char *info2;
	int player_pos_i;
	int player_pos_j;
	int direction;
}	t_mlx_data;


typedef struct s_map_info
{
	int empty;
	int wall;
	int collectible;
	int	exit;
	int starting;
	int enimies;
}	t_map_info;

int		map_valid(char **lines);
int 	map_walls(char **lines);
int		parse_map(char **lines);
void	free_array(char **lines);
void load_game(char **map);
int map_calculate(char **s, char c);
void    game_over(t_mlx_data *mlx_data, int *pos_i, int *pos_j);
void win_game(t_mlx_data *mlx_data, int *pos_i, int *pos_j);
void    mlx_move_enemies(t_mlx_data *mlx_data);
void    load_enemies(t_mlx_data *mlx_data);
#endif