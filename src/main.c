/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:57 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/18 18:49:38 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	window(t_map *map);

int main(int ac, char **av)
{
	char	*map_file = av[1];
	int 	i = 0;
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
	while (i < map->nbr_line)
	{
		printf("%s\n",map->map[i]);//temp test
		i++;
	}
	window(map);
	free_map(map);
}

static int	key_hook(int keycode, t_map *map)
{
		char	tmp;
		char	**tab;
		int		i = 0;

		tab = map->map;
		if (keycode == 'w')
			{
				tmp = tab[16][1];
				tab[16][1] = tab[15][1];
				tab[15][1] = tmp;
				while (i < map->nbr_line)
				{
					printf("%s\n",map->map[i]);//temp test
					i++;
				}
			}
		return (0);
}
/*
static void	frame_buffer()
{

}
*/
static void	map_to_window(void *mlx, void *mlx_win, t_map *map)
{
	int		i;
	int		j;
	t_img	ground;
	t_img	wall;
	t_img	cat;
	t_img	frame;
	char	*wall_path = "textures/rock.xpm";
	char	*grass_path = "textures/grass.xpm";
	char	*cat_path = "textures/cat.xpm";
	int		pos_x;
	int		pos_y;
	char 	*pixel;

	unsigned int	color;
/*	
	frame = malloc(sizeof(t_img));
	wall = malloc(sizeof(t_img));
	cat = malloc(sizeof(t_img));
	player = malloc(sizeof(t_img));
	ground = malloc(sizeof(t_img));
	if (!frame || !wall || !cat || !player || !ground)
		return ;*/
	frame.img = mlx_new_image(mlx, map->len_line * 32, map->nbr_line * 32);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len, &frame.endian);

	ground.img = mlx_xpm_file_to_image(mlx, grass_path, &ground.width, &ground.height);
	ground.addr = mlx_get_data_addr(ground.img, &ground.bpp, &ground.line_len, &ground.endian);

	cat.img = mlx_xpm_file_to_image(mlx, cat_path, &cat.width, &cat.height);
	cat.addr = mlx_get_data_addr(cat.img, &cat.bpp, &cat.line_len, &cat.endian);

	wall.img = mlx_xpm_file_to_image(mlx, wall_path, &wall.width, &wall.height);
	wall.addr = mlx_get_data_addr(wall.img, &wall.bpp, &wall.line_len, &wall.endian);
	
	pos_y = 0;
	while (pos_y < map->nbr_line * 32)
	{
		i = -1;
		while (++i < 32)
		{
			pos_x = 0;
			while (pos_x < map->len_line * 32)
			{
				j = -1;
				while (++j < 32)
				{
					pixel = frame.addr + ((pos_y) * frame.line_len + (pos_x) * (frame.bpp / 8));
					*(unsigned int *)pixel = *(unsigned int *)(ground.addr + (i * ground.line_len + j * (ground.bpp / 8)));	
					if (map->map[pos_y/32][pos_x/32] == WALL)
					{
						pixel = frame.addr + ((pos_y) * frame.line_len + (pos_x) * (frame.bpp / 8));
						*(unsigned int *)pixel = *(unsigned int *)(wall.addr + (i * wall.line_len + j * (wall.bpp / 8)));
					}
					else if (map->map[pos_y/32][pos_x/32] == PLAYER)
					{
						pixel = frame.addr + ((pos_y) * frame.line_len + (pos_x) * (frame.bpp / 8));
						color = *(unsigned int *)(cat.addr + (i * cat.line_len + j * (cat.bpp / 8)));
						if (color != 4278190080)
								*(unsigned int *)pixel = color;
					}
					pos_x += 1;
				}
			}
			pos_y += 1;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, frame.img, 0, 0);
}

static void	window(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->len_line * 32, map->nbr_line * 32, "boop");
	map_to_window(mlx, mlx_win, map);
	mlx_key_hook(mlx_win, key_hook, map);
	mlx_loop(mlx);
}
