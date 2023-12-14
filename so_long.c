/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-rhay <mel-rhay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:33 by mel-rhay          #+#    #+#             */
/*   Updated: 2023/12/14 21:25:45 by mel-rhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(int fd)
{
	char **str;
	
}

int main(int ac, char **av)
{
	char **lines;
	int fd;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			printf("Error\n");
		lines = read_map(fd);
	}
	else
	{
		printf("Error\n");
	}
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