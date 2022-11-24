/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:58:52 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 11:27:28 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	new_square(t_arg *arg)
{
	t_pixel	*pixel;
	t_map	*map;

	pixel = malloc(sizeof(t_pixel));
	if (!pixel)
		ft_exit_failure(arg);
	map = arg->map;
	pixel->y_fr = 32 * arg->player->y;
	while (pixel->y_fr < 32 * arg->player->y + 32)
	{
		pixel->x_fr = 32 * arg->player->x;
		while (pixel->x_fr < 32 * arg->player->x + 32)
		{
			pixel_texture_to_frame(arg, arg->sprites, arg->frame, *pixel);
			pixel->x_fr += 1;
		}
		pixel->y_fr += 1;
	}
	free(pixel);
}

void	sprite_to_window(t_arg *arg)
{
	t_map		*map;
	void		*mlx;
	void		*mlx_win;

	map = arg->map;
	mlx = arg->mlx;
	mlx_win = arg->mlx_win;
	new_square(arg);
	mlx_put_image_to_window(mlx, mlx_win, arg->frame->img, 0, 0);
}

static void	draw_first_frame(t_arg *arg)
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

void	map_to_window(t_arg *arg)
{
	void		*mlx;
	void		*mlx_win;

	mlx = arg->mlx;
	mlx_win = arg->mlx_win;
	draw_first_frame(arg);
	mlx_put_image_to_window(mlx, mlx_win, arg->frame->img, 0, 0);
}

void	destroy_image(void *mlx, t_textures *sprites)
{
	if (sprites->wll.img)
		mlx_destroy_image(mlx, sprites->wll.img);
	if (sprites->grd.img)
		mlx_destroy_image(mlx, sprites->grd.img);
	if (sprites->ext.img)
		mlx_destroy_image(mlx, sprites->ext.img);
	if (sprites->plr.img)
		mlx_destroy_image(mlx, sprites->plr.img);
	if (sprites->obj.img)
		mlx_destroy_image(mlx, sprites->obj.img);
}
