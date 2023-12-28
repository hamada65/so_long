/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:33 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/28 01:11:14 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_lines(char *file)
{
	int		lines_num;
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	lines_num = 0;
	str = get_next_line(fd);
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

char	**read_map(char *file)
{
	char	**str;
	char	*tmp;
	int		lines_num;
	int		fd;
	int		i;

	lines_num = file_lines(file);
	str = (char **)malloc(sizeof(char *) * (lines_num) + 1);
	if (!str)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while (i < lines_num)
	{
		tmp = get_next_line(fd);
		if (ft_strncmp(tmp, "\n", 1))
			str[i++] = ft_strtrim(tmp, "\n");
		free(tmp);
	}
	str[lines_num] = 0;
	close(fd);
	return (str);
}

int	check_file_name(char *file_name)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(file_name);
	if (len >= 5)
	{
		if (file_name[len] == '\0' && file_name[len - 1] == 'r'
			&& file_name[len - 2] == 'e'
			&& file_name[len - 3] == 'b' && file_name[len - 4] == '.')
			return (1);
	}
	return (0);
}

char	**check_and_read(char *file)
{
	char	**lines;

	if (!check_file_name(file))
	{
		ft_printf("Error\nInvalid File Name");
		return (NULL);
	}
	lines = read_map(file);
	if (!lines)
	{
		ft_printf("Error\nCan`t Read Map");
		return (0);
	}
	if (!map_valid(lines) || !map_walls(lines) || !parse_map(lines))
	{
		ft_printf("Error\nInvalid Map");
		free_array(lines);
		return (NULL);
	}
	return (lines);
}

int	main(int ac, char **av)
{
	char	**lines;
	int		i;

	i = 0;
	if (ac == 2)
	{
		lines = check_and_read(av[1]);
		if (!lines)
			return (0);
		load_game(lines);
	}
	else
		ft_printf("Error\nMissing Args");
	return (0);
}
