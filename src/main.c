/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:57 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/11 16:43:42 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	window(t_map *map);

int main(int ac, char **av)
{
	char	*map_file = av[1];
	//int 	i = 0;
	t_map 	*map;

	if (ac > 2)
	{
		ft_putstr_fd("Error\nTo many arguments\n", 1);
		return (-1);
	}
	if(file_error(map_file) != 0)
		return (-1);
	map = parse_map(map_file);
	if (map_error(map) != 0)
	{
		free_map(map);
		return (-1);
	}
	/*
	while (i < map->nbr_line)
	{
		printf("%s\n",map->map[i]);//temp test
		i++;
	}*/
	window(map);
	free_map(map);
}

static void	map_to_window(void *mlx, void *mlx_win, t_map *map)
{
	int		i;
	int		j;
	void	*img;
	char	*wall = "textures/rock.xpm";
	char	*grass = "textures/grass.xpm";
	int		img_width;
	int		img_height;
	int		pos_x;
	int		pos_y;

	i = -1;
	pos_y = 0;
	while (map->map[++i])
	{
			j = -1;
			pos_x = 0;
			printf("%d >%s\n", i,map->map[i]);//temp test
			while (map->map[i][++j])
			{
					img = mlx_xpm_file_to_image(mlx, grass, &img_width, &img_height);
					mlx_put_image_to_window(mlx, mlx_win, img, pos_x, pos_y);
					if (map->map[i][j] == '1')
							img = mlx_xpm_file_to_image(mlx, wall, &img_width, &img_height);
					mlx_put_image_to_window(mlx, mlx_win, img, pos_x, pos_y);
					pos_x += 32;
			}
			pos_y += 32;
	}
}

static void	window(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->len_line * 32, map->nbr_line * 32, "boop");
	map_to_window(mlx, mlx_win, map);
	mlx_loop(mlx);
}

