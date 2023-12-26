/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:33 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/26 22:27:53 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int file_lines(int fd)
{
	int lines_num;
	char *str;
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
	return (lines_num);
}

char **read_map(char *file)
{
	char **str;
	char *tmp;
	int lines_num;
	int fd;
	int i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines_num = file_lines(fd);
	close(fd);
	str = (char **)malloc(sizeof(char *)*(lines_num) + 1);
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

int check_file_name(char *file_name)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(file_name);
	if (len >= 5)
	{
		printf("file_name = %s\n", file_name);
		if (file_name[len] == '\0' && file_name[len - 1] == 'r' && file_name[len - 2] == 'e' && file_name[len - 3] == 'b' && file_name[len - 4] == '.')
			return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	char **lines;
	int i = 0;
	printf("ac = %d\n", ac);
	if (ac == 2)
	{
		if (!check_file_name(av[1]))
		{
			printf("Error\nInvalid File Name");
			return (0);
		}
		lines = read_map(av[1]);
		if (!lines)
		{
			printf("Error\nInvalid Map");
			return (0);
		}
		if (!map_valid(lines) || !map_walls(lines) || !parse_map(lines))
		{
			printf("Error\nInvalid Map");
			free_array(lines);
			return (0);
		}
		load_game(lines);
		printf("end Game\n");
		// printf("Map Valid\n");
		// free_array(lines);
	}
	else
		printf("Error\nMissing Args");
	return (0);
}

// int render_map2(t_mlx_data *mlx_data)
// {
// 	static int i = 0;
// 	i++;
// 	if (i == 100000/2)
// 	{
// 		mlx_clear_window(mlx_data->mlx_ptr, mlx_data->mlx_window);
// 		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->mlx_window, mlx_data->exit.img, 120, 120);
// 	}
// 	else if (i == 100000)
// 	{
// 		mlx_clear_window(mlx_data->mlx_ptr, mlx_data->mlx_window);
// 		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->exit.img);
// 		exit(0);
// 	}
// 	return 0;
// }

// int main()
// {
// 	t_mlx_data mlx_data;

// 	mlx_data.mlx_ptr = mlx_init();
// 	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_ptr, 1920, 1080, "hamada");
// 	mlx_data.exit.img = mlx_xpm_file_to_image(mlx_data.mlx_ptr, "srcs/img/exit.xpm", &mlx_data.exit.width, &mlx_data.exit.height);
// 	mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.mlx_window, mlx_data.exit.img, 60, 60);
// 	mlx_loop_hook(mlx_data.mlx_ptr, &render_map2, &mlx_data);
// 	mlx_loop(mlx_data.mlx_ptr);
// 	return 0;
// }