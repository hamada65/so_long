/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:26 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 21:00:12 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "srcs/get_next_line/get_next_line.h"
# include "srcs/libft/libft.h"
# include "srcs/printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// Coins animations speed (millseconds)
# ifndef COINS_ANIM_SPEED
#  define COINS_ANIM_SPEED 30
# endif

// Player animations speed (millseconds)
# ifndef PLAYER_ANIM_SPEED
#  define PLAYER_ANIM_SPEED 300
# endif

typedef struct img_info
{
	int				width;
	int				height;
	int				pos_i;
	int				pos_j;
	void			*img;
}					t_img_info;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*mlx_window;
	char			**map;
	int				map_size_x;
	int				map_size_y;
	t_img_info		wall;
	t_img_info		floor;
	t_img_info		coin;
	t_img_info		player_left;
	t_img_info		exit;
	t_img_info		exit_opened;
	t_img_info		win;
	t_img_info		black_img;
	t_img_info		white_img;
	int				required_coins;
	int				collected_coins;
	int				moves;
	int				player_pos_i;
	int				player_pos_j;
}					t_mlx_data;

typedef struct s_map_info
{
	int				empty;
	int				wall;
	int				collectible;
	int				exit;
	int				starting;
	int				enimies;
}					t_map_info;

typedef struct coin_info
{
	int				collected_coins;
	int				required_coins;
}					t_coin_info;

char				**read_map(char *file);
int					map_valid(char **lines);
int					map_walls(char **lines);
int					parse_map(char **lines);
void				free_array(char **lines);
void				load_game(char **map);
int					map_calculate(char **s, char c);
void				win_game(t_mlx_data *mlx_data);
int					destroy_game(t_mlx_data *mlx_data);
int					map_lines(char **lines);
void				get_start_pos(char **lines, int *i, int *j);
char				**ft_strdup_array(char **lines);
void				load_images(t_mlx_data *mlx_data);
void				data_init(t_mlx_data *mlx_data, char **map);
int					key_release(int keycode, t_mlx_data *mlx_data);
void				check_pos(t_mlx_data *mlx_data);
void				put_textures(t_mlx_data *mlx_data, char **map, int i,
						int j);
#endif