/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:58:52 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/22 17:42:08 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pixel_texture_to_frame(t_arg *arg, t_textures sprite, t_img frame,
		t_pixel pxl)
{
	t_map		*map;
	t_player	*player;

	map = arg->map;
	player = arg->player;
	set_pixel_color(sprite.grd, frame, pxl);
	if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == WALL)
		set_pixel_color(sprite.wll, frame, pxl);
	else if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == PLAYER)
	{
		if (player->is_on_exit == 1)
			set_pixel_color(sprite.ext, frame, pxl);
		set_pixel_color(sprite.plr, frame, pxl);
	}
	else if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == OBJ)
		set_pixel_color(sprite.obj, frame, pxl);
	else if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == EXIT)
		set_pixel_color(sprite.ext, frame, pxl);
}

static t_img	frame_buffer(t_arg *arg, t_textures sprites, t_img frame)
{
	t_pixel	pixel;
	t_map	*map;

	map = arg->map;
	pixel.y_fr = 0;
	while (pixel.y_fr < map->nbr_line * 32)
	{
		pixel.y_sp = -1;
		while (++pixel.y_sp < 32)
		{
			pixel.x_fr = 0;
			while (pixel.x_fr < map->len_line * 32)
			{
				pixel.x_sp = -1;
				while (++pixel.x_sp < 32)
				{
					pixel_texture_to_frame(arg, sprites, frame, pixel);
					pixel.x_fr += 1;
				}
			}
			pixel.y_fr += 1;
		}
	}
	return (frame);
}

static t_img	textures_init(void *mlx, char *path)
{
	t_img	sprite;

	sprite.path = path;
	sprite.img = mlx_xpm_file_to_image(mlx, sprite.path, &sprite.width,
			&sprite.height);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bpp,
			&sprite.line_len, &sprite.endian);
	return (sprite);
}
/*#include <stdio.h>
void	print_map(t_map *map)
{
	int 		i = 0;
	int			j;
	char		c;

	while (i < map->nbr_line)
	{
		j = 0;
		while (j < map->len_line)
		{
			c = map->map[i][j];
			if (c == PLAYER)
				printf("\033[0;34m%c",c);//temp test
			else if (c == '9')
				printf("\033[0;31m%c",c);//temp test
			else if (c == OBJ)
				printf("\033[0;32m%c",c);//temp test
			else if (c == EXIT)
				printf("\033[0;33m%c",c);//temp test
			else
				printf("\033[0m%c",c);//temp test
			j++;
		}
		printf("\n");//temp test
		i++;
	}
}*/

void	map_to_window(t_arg *arg)
{
	t_textures	sprites;
	t_img		frame;
	t_map		*map;
	void		*mlx;
	void		*mlx_win;

	map = arg->map;
	mlx = arg->mlx;
	mlx_win = arg->mlx_win;
	frame.path = NULL;
	frame.img = mlx_new_image(mlx, map->len_line * 32, map->nbr_line * 32);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len,
			&frame.endian);
	sprites.wll = textures_init(mlx, "textures/rock.xpm");
	sprites.grd = textures_init(mlx, "textures/grass.xpm");
	sprites.plr = textures_init(mlx, "textures/cat.xpm");
	sprites.ext = textures_init(mlx, "textures/car.xpm");
	sprites.obj = textures_init(mlx, "textures/shrinp.xpm");
	frame_buffer(arg, sprites, frame);
	mlx_put_image_to_window(mlx, mlx_win, frame.img, 0, 0);
}

void	window(t_map *map)
{
	void		*mlx;
	void		*mlx_win;
	t_player	*player;
	t_arg		*arg;

	player = malloc(sizeof(t_player));
	if (!player)
		exit(EXIT_FAILURE);
	arg = malloc(sizeof(t_arg));
	if (!arg)
		exit(EXIT_FAILURE);
	player->x = map->start_x;
	player->y = map->start_y;
	player->is_on_exit = 0;
	player->steps = 0;
	arg->map = map;
	arg->player = player;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->len_line * 32, map->nbr_line * 32,
			"so_long");
	arg->mlx = mlx;
	arg->mlx_win = mlx_win;
	map_to_window(arg);
	mlx_key_hook(mlx_win, key_hook, arg);
	mlx_loop(mlx);
}
