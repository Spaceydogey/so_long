/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:58:52 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/23 13:51:16 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pixel_texture_to_frame(t_arg *arg, t_textures *sprite, t_img *frame,
		t_pixel pxl)
{
	t_map		*map;
	t_player	*player;

	map = arg->map;
	player = arg->player;
	set_pixel_color(sprite->grd, frame, pxl);
	if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == WALL)
		set_pixel_color(sprite->wll, frame, pxl);
	else if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == PLAYER)
	{
		if (player->is_on_exit == 1)
			set_pixel_color(sprite->ext, arg->frame, pxl);
		set_pixel_color(sprite->plr, frame, pxl);
	}
	else if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == OBJ)
		set_pixel_color(sprite->obj, frame, pxl);
	else if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == EXIT)
		set_pixel_color(sprite->ext, frame, pxl);
}

static void	frame_buffer(t_arg *arg)
{
	t_pixel	pixel;
	t_map	*map;

	map = arg->map;
	pixel.y_fr = 0;
	while (pixel.y_fr < map->nbr_line * 32)
	{
		pixel.x_fr = 0;
		while (pixel.x_fr < map->len_line * 32)
		{
			pixel_texture_to_frame(arg, arg->sprites, arg->frame, pixel);
			pixel.x_fr += 1;
		}
		pixel.y_fr += 1;
	}
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
	t_map		*map;
	void		*mlx;
	void		*mlx_win;

	map = arg->map;
	mlx = arg->mlx;
	mlx_win = arg->mlx_win;
	frame_buffer(arg);
	mlx_put_image_to_window(mlx, mlx_win, arg->frame->img, 0, 0);
}

void	window(t_map *map)
{
	void		*mlx;
	void		*mlx_win;
	t_arg		*arg;
	t_player	*player;

	player = player_init(map);
	mlx = mlx_init();
	if (!mlx)
		exit(EXIT_FAILURE);
	mlx_win = mlx_new_window(mlx, map->len_line * 32, map->nbr_line * 32,
			"so_long");
	if (!mlx_win)
		exit(EXIT_FAILURE);
	arg = arg_init(mlx, mlx_win, player, map);
	arg->frame->img = mlx_new_image(mlx, map->len_line * 32, map->nbr_line * 32);
	arg->frame->addr = mlx_get_data_addr(arg->frame->img, &arg->frame->bpp,
			&arg->frame->line_len, &arg->frame->endian);
	arg->frame->path = NULL;
	arg->sprites->wll = textures_init(mlx, "textures/rock.xpm");
	arg->sprites->grd = textures_init(mlx, "textures/grass.xpm");
	arg->sprites->plr = textures_init(mlx, "textures/cat.xpm");
	arg->sprites->ext = textures_init(mlx, "textures/test.xpm");
	arg->sprites->obj = textures_init(mlx, "textures/shrinp.xpm");
	map_to_window(arg);
	mlx_hook(mlx_win, 17, 0, ft_exit, arg);
	mlx_key_hook(mlx_win, key_hook, arg);
	mlx_loop(mlx);
}
