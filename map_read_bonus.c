/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:35:38 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 19:38:54 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	file_lines(char *file)
{
	int		lines_num;
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	lines_num = 0;
	str = get_next_line(fd);
	if (!str)
		return (0);
	while (str)
	{
		if (ft_strncmp(str, "\n", 2))
			lines_num++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (lines_num);
}

void	make_map(char **str, int lines_num, int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < lines_num)
	{
		tmp = get_next_line(fd);
		if (ft_strncmp(tmp, "\n", 1))
			str[i++] = ft_strtrim(tmp, "\n");
		free(tmp);
	}
	str[lines_num] = 0;
}

char	**read_map(char *file)
{
	char	**str;
	int		lines_num;
	int		fd;

	lines_num = file_lines(file);
	if (!lines_num)
		return (0);
	str = (char **)malloc(sizeof(char *) * (lines_num) + 1);
	if (!str)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	make_map(str, lines_num, fd);
	close(fd);
	return (str);
}
