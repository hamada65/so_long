/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:26 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/14 21:13:45 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
# include <fcntl.h>
#include <string.h>

typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *mlx_window;
	void *wall;
	void *player;
}	t_mlx_data;


typedef struct s_map_info
{
	int empty;
	int wall;
	int collectible;
	int	exit;
	int starting;
}	t_map_info;

typedef struct s_list
{
	char			*buff;
	struct s_list	*next;
}					t_list;

int		map_valid(int fd);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
//libft
size_t				ft_strlen(const char *s);
#endif