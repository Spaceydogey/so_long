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
		if (keycode = 'w')
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

static void	frame_buffer()
{

}

static void	map_to_window(void *mlx, void *mlx_win, t_map *map)
{
	int		i;
	int		j;
	void	*img;
	char	*img_addr;
	int		img_bpp;
	int		img_line_len;
	int		img_endian;
	int		bpp;

	void	*imgwall;
	char	*imgwall_addr;
	int		imgwall_bpp;
	int		imgwall_line_len;
	int		imgwall_endian;
	int		imgwall_width;
	int		imgwall_height;

	void	*imgcat;
	char	*imgcat_addr;
	int		imgcat_bpp;
	int		imgcat_line_len;
	int		imgcat_endian;
	int		imgcat_width;
	int		imgcat_height;

	int 	line_len;
	int		endian;
	void	*frame;
	char	*frame_addr;
	char	*wall = "textures/rock.xpm";
	char	*grass = "textures/grass.xpm";
	char	*cat = "textures/cat.xpm";
	int		img_width;
	int		img_height;
	int		pos_x;
	int 	x;
	int		pos_y;
	int		y;
	char 	*pixel;

	unsigned int	color;

	frame = mlx_new_image(mlx, map->len_line * 32, map->nbr_line * 32);
	frame_addr = mlx_get_data_addr(frame, &bpp, &line_len, &endian);

	img = mlx_xpm_file_to_image(mlx, grass, &img_width, &img_height);
	img_addr = mlx_get_data_addr(img, &img_bpp, &img_line_len, &img_endian);

	imgcat = mlx_xpm_file_to_image(mlx, cat, &imgcat_width, &imgcat_height);
	imgcat_addr = mlx_get_data_addr(imgcat, &imgcat_bpp, &imgcat_line_len, &imgcat_endian);

	imgwall = mlx_xpm_file_to_image(mlx, wall, &imgwall_width, &imgwall_height);
	imgwall_addr = mlx_get_data_addr(imgwall, &imgwall_bpp, &imgwall_line_len, &imgwall_endian);
	
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
					pixel = frame_addr + ((pos_y) * line_len + (pos_x) * (bpp / 8));
					*(unsigned int *)pixel = *(unsigned int *)(img_addr + (i * img_line_len + j * (img_bpp / 8)));	
					if (map->map[pos_y/32][pos_x/32] == WALL)
					{
						pixel = frame_addr + ((pos_y) * line_len + (pos_x) * (bpp / 8));
						*(unsigned int *)pixel = *(unsigned int *)(imgwall_addr + (i * imgwall_line_len + j * (imgwall_bpp / 8)));
					}
					else if (map->map[pos_y/32][pos_x/32] == PLAYER)
					{
						pixel = frame_addr + ((pos_y) * line_len + (pos_x) * (bpp / 8));
						color = *(unsigned int *)(imgcat_addr + (i * imgcat_line_len + j * (imgcat_bpp / 8)));
						if (color != 4278190080)
								*(unsigned int *)pixel = color;
					}
					pos_x += 1;
				}
			}
			pos_y += 1;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, frame, 0, 0);
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
