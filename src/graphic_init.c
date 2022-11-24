/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:56:15 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 10:23:20 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_arg	*arg_init(void *mlx, void *mlx_win,
		t_player *player, t_map *map)
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

static t_player	*player_init(t_map *map)
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

static void	arg_sprites_init(t_arg *arg)
{
	arg->sprites->wll = textures_init(arg->mlx, "textures/rock.xpm");
	arg->sprites->grd = textures_init(arg->mlx, "textures/grass.xpm");
	arg->sprites->plr = textures_init(arg->mlx, "textures/cat.xpm");
	arg->sprites->ext = textures_init(arg->mlx, "textures/test.xpm");
	arg->sprites->obj = textures_init(arg->mlx, "textures/shrinp.xpm");
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
	arg->frame->img = mlx_new_image(mlx, map->len_line * 32,
			map->nbr_line * 32);
	arg->frame->addr = mlx_get_data_addr(arg->frame->img, &arg->frame->bpp,
			&arg->frame->line_len, &arg->frame->endian);
	arg->frame->path = NULL;
	arg_sprites_init(arg);
	map_to_window(arg);
	mlx_hook(mlx_win, 17, 0, ft_exit, arg);
	mlx_key_hook(mlx_win, key_hook, arg);
	mlx_loop(mlx);
}
