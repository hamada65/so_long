/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:33 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/21 22:40:48 by mel-rhay         ###   ########.fr       */
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
		str[i] = ft_strtrim(tmp, "\n");
		free(tmp);
		i++;
	}
	str[lines_num] = 0;
	close(fd);
	return (str);
}

int main(int ac, char **av)
{
	char **lines;
	int i = 0;
	printf("ac = %d\n", ac);
	if (ac == 2)
	{
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
		printf("Map Valid\n");
		free_array(lines);
	}
	else
		printf("Error\nMissing Args");
	return (0);
}

//int key_press(int key, t_mlx_data *mlx_data)
//{
//	mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->player);
//	printf("key %d Pressed.\n", key);
//	return (1);
//}


//int main()
//{
//	t_mlx_data mlx_data;
//	int		img_width;
//	int		img_height;

//	mlx_data.mlx_ptr = mlx_init();
//	if (!mlx_data.mlx_ptr)
//		return (0);
//	mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_ptr, 60*20, 60*10, "So Long 1337");
//	if (!mlx_data.mlx_window)
//	{
//		mlx_destroy_display(mlx_data.mlx_ptr);
//		free(mlx_data.mlx_ptr);
//		return (0);
//	}
//	mlx_data.wall = mlx_xpm_file_to_image(mlx_data.mlx_ptr, "srcs/img/ground5.xpm", &img_width, &img_height);
//	mlx_data.player = mlx_xpm_file_to_image(mlx_data.mlx_ptr, "srcs/img/player.xpm", &img_width, &img_height);
//	if (!mlx_data.wall || !mlx_data.player)
//	{
//		mlx_destroy_display(mlx_data.mlx_ptr);
//		free(mlx_data.mlx_ptr);
//		printf("error while loading img\n");
//		return (0);
//	}
//	//int size = 20*10;
//	int i, j;
//	// i = line, j = column
//	printf("start rendring map\n");
//	i = 0;
//	while (i < 20)
//	{
//		j = 0;
//		while (j < 10)
//		{
//			printf("i = %d, j = %d, coords 1 = %d, coords 2 = %d\n", i, j, i*60, j*60);
//			mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.mlx_window, mlx_data.wall, i*60, j*60);
//			j++;
//		}
//		printf("new line\n");
//		i++;
//	}
//	mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.mlx_window, mlx_data.player, 0, 0);
//	//mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.mlx_window, img, 0, 0);
//	//mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.mlx_window, img, 0, 60);
//	mlx_key_hook(mlx_data.mlx_window, &key_press, &mlx_data);
//	mlx_loop(mlx_data.mlx_ptr);
//	mlx_destroy_display(mlx_data.mlx_ptr);
//	free(mlx_data.mlx_ptr);
//	return 0;
//}