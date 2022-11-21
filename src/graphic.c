/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:58:52 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/21 20:22:23 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// add exit and obj on the map
static void	pixel_texture_to_frame(t_map *map, t_textures sprite, t_img frame,
		t_cp_pixel pxl)
{
	char	*pxl_clr;
	uint	clr;

	pxl_clr = frame.addr + ((pxl.y_fr) * frame.line_len + (pxl.x_fr)
			* (frame.bpp / 8));
	*(uint *)pxl_clr = *(uint *)(sprite.grd.addr + (pxl.y_sp
				* sprite.grd.line_len + pxl.x_sp * (sprite.grd.bpp / 8)));
	if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == WALL)
	{
		pxl_clr = frame.addr + ((pxl.y_fr)
				* frame.line_len + (pxl.x_fr) * (frame.bpp / 8));
		*(uint *)pxl_clr = *(uint *)(sprite.wll.addr + (pxl.y_sp
					* sprite.wll.line_len + pxl.x_sp * (sprite.wll.bpp / 8)));
	}
	else if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == PLAYER)
	{
		pxl_clr = frame.addr + ((pxl.y_fr)
				* frame.line_len + (pxl.x_fr) * (frame.bpp / 8));
		clr = *(uint *)(sprite.plr.addr + (pxl.y_sp
					* sprite.plr.line_len + pxl.x_sp * (sprite.plr.bpp / 8)));
		if (clr != 4278190080)
			*(uint *)pxl_clr = clr;
	}
	else if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == OBJ)
	{
		pxl_clr = frame.addr + ((pxl.y_fr)
				* frame.line_len + (pxl.x_fr) * (frame.bpp / 8));
		clr = *(uint *)(sprite.obj.addr + (pxl.y_sp
					* sprite.obj.line_len + pxl.x_sp * (sprite.obj.bpp / 8)));
		if (clr != 4278190080)
			*(uint *)pxl_clr = clr;
	}
	else if (map->map[pxl.y_fr / 32][pxl.x_fr / 32] == EXIT)
	{
		pxl_clr = frame.addr + ((pxl.y_fr)
				* frame.line_len + (pxl.x_fr) * (frame.bpp / 8));
		clr = *(uint *)(sprite.ext.addr + (pxl.y_sp
					* sprite.ext.line_len + pxl.x_sp * (sprite.ext.bpp / 8)));
		if (clr != 4278190080)
			*(uint *)pxl_clr = clr;
	}

}

static t_img	frame_buffer(t_map *map, t_textures sprites, t_img frame)
{
	t_cp_pixel	pixel;

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
					pixel_texture_to_frame(map, sprites, frame, pixel);
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

void	map_to_window(void *mlx, void *mlx_win, t_map *map)
{
	t_textures	sprites;
	t_img		frame;

	frame.path = NULL;
	frame.img = mlx_new_image(mlx, map->len_line * 32, map->nbr_line * 32);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bpp, &frame.line_len,
			&frame.endian);
	sprites.wll = textures_init(mlx, "textures/rock.xpm");
	sprites.grd = textures_init(mlx, "textures/grass.xpm");
	sprites.plr = textures_init(mlx, "textures/cat.xpm");
	sprites.ext = textures_init(mlx, "textures/car.xpm");
	sprites.obj = textures_init(mlx, "textures/shrinp.xpm");
	frame_buffer(map, sprites, frame);
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
	{
		//free
		return ;
	}
	arg = malloc(sizeof(t_arg));
	if (!arg)
	{
		//free
		return ;
	}
	player->x = map->start_x;
	player->y = map->start_y;
	player->is_on_exit = 0;
	player->steps = 0;
	arg->map = map;
	arg->player = player;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, map->len_line * 32, map->nbr_line * 32,
			"boop");
	map_to_window(mlx, mlx_win, map);
	arg->mlx = mlx;
	arg->mlx_win = mlx_win;
	mlx_key_hook(mlx_win, key_hook, arg);
	mlx_loop(mlx);
}
