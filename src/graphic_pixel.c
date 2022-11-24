/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:56:39 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 10:20:07 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_pixel_color(t_img src, t_img *dst, t_pixel pxl)
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

void	pixel_texture_to_frame(t_arg *arg, t_textures *sprite, t_img *frame,
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
