/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:56:39 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/23 14:19:55 by hdelmas          ###   ########.fr       */
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
