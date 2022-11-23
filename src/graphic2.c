/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:56:39 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/23 17:14:35 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_arg	*arg_init(void *mlx, void *mlx_win, t_player *player, t_map *map)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		exit(EXIT_FAILURE);
	arg->map = map;
	arg->player = player;
	arg->mlx = mlx;
	arg->mlx_win = mlx_win;
	arg->sprites = malloc(sizeof(t_textures));
	if (!arg->sprites)
		exit(EXIT_FAILURE);
	arg->frame = malloc(sizeof(t_img));
	if (!arg->frame)
		exit(EXIT_FAILURE);
	return (arg);
}

t_player	*player_init(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		exit(EXIT_FAILURE);
	player->x = map->start_x;
	player->y = map->start_y;
	player->is_on_exit = 0;
	player->steps = 0;
	return (player);
}
/*
#include <stdio.h>
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

void	srpite_to_window(t_arg *arg)
{
	t_map		*map;
	void		*mlx;
	void		*mlx_win;

	//printf("col : %d, line : %d\n",  arg->player->x,  arg->player->y);
	map = arg->map;
	mlx = arg->mlx;
	mlx_win = arg->mlx_win;
	new_square(arg);
//	print_map(arg->map);
	mlx_put_image_to_window(mlx, mlx_win, arg->frame->img, 0, 0);
}

void	new_square(t_arg *arg)
{
	t_pixel	*pixel;
	t_map	*map;

	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		exit(EXIT_FAILURE);
	map = arg->map;
	pixel->y_fr = 32 *arg->player->y;
	while (pixel->y_fr < 32 * arg->player->y + 32)
	{
		pixel->x_fr = 32 * arg->player->x;
		//printf("col : %d, line : %d\n", 32 * arg->player->x,  32 * arg->player->y);
		//printf("pixel x : %d, pixel line : %d\n",  32 * pixel->x_fr,  32 * pixel->y_fr);
		while (pixel->x_fr < 32 * arg->player->x + 32)
		{
			pixel_texture_to_frame(arg, arg->sprites, arg->frame, *pixel);
			pixel->x_fr += 1;
		}
		pixel->y_fr += 1;
	}
}

void	set_pixel_color(t_img src, t_img *dst, t_pixel pxl)
{
	char	*pxl_addr;
	t_uint	clr;

	pxl_addr = dst->addr + ((pxl.y_fr)
			* dst->line_len + (pxl.x_fr) * (dst->bpp / 8));
	clr = *(t_uint *)(src.addr + (pxl.y_fr % 32 * src.line_len
				+ pxl.x_fr % 32 * (src.bpp / 8)));
	if (clr != 4278190080)
		*(t_uint *)pxl_addr = clr;
}

void	destroy_image(void *mlx, t_textures *sprites)
{
	mlx_destroy_image(mlx, sprites->wll.img);
	mlx_destroy_image(mlx, sprites->grd.img);
	mlx_destroy_image(mlx, sprites->ext.img);
	mlx_destroy_image(mlx, sprites->plr.img);
	mlx_destroy_image(mlx, sprites->obj.img);
}
