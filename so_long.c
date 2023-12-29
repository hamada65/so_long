/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:33 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/29 20:06:39 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			&& file_name[len - 3] == 'b'
			&& file_name[len - 4] == '.')
			return (1);
	}
	return (0);
}

int	check_characters(char **lines)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (!(lines[i][j] == '0' || lines[i][j] == '1' || lines[i][j] == 'C'
					|| lines[i][j] == 'E' || lines[i][j] == 'P'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**check_and_read(char *file)
{
	char	**lines;
	char	*tmp;

	tmp = ft_strtrim(file, " ");
	if (!check_file_name(tmp))
	{
		ft_printf("Error\nInvalid File Name");
		free(tmp);
		return (NULL);
	}
	lines = read_map(tmp);
	free(tmp);
	if (!lines)
	{
		ft_printf("Error\nCan`t Read Map");
		return (0);
	}
	if (!check_characters(lines) || !map_valid(lines) || !map_walls(lines)
		|| !parse_map(lines))
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
		ft_printf("Error\nInvalid Args");
	return (0);
}
