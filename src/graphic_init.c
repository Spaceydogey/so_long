/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:56:15 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/25 14:35:30 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static t_arg	*arg_init(t_map *map)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		exit(EXIT_FAILURE);
	arg->map = map;
	arg->player = player_init(map);
	arg->mlx = mlx_init();
	if (!arg->mlx)
		exit(EXIT_FAILURE);
	arg->mlx_win = mlx_new_window(arg->mlx, map->len_line * 32,
			map->nbr_line * 32, "so_long");
	if (!arg->mlx_win)
		exit(EXIT_FAILURE);
	arg->sprites = malloc(sizeof(t_textures));
	if (!arg->sprites)
		exit(EXIT_FAILURE);
	arg->frame = malloc(sizeof(t_img));
	if (!arg->frame)
		exit(EXIT_FAILURE);
	return (arg);
}

static t_img	textures_init(t_arg *arg, char *path)
{
	t_img	sprite;

	sprite.path = path;
	sprite.img = mlx_xpm_file_to_image(arg->mlx, sprite.path, &sprite.width,
			&sprite.height);
	if (!sprite.img)
		ft_exit_failure(arg);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bpp,
			&sprite.line_len, &sprite.endian);
	if (!sprite.addr)
		ft_exit_failure(arg);
	return (sprite);
}

static void	arg_sprites_init(t_arg *arg)
{
	arg->sprites->wll = textures_init(arg, "textures/rock.xpm");
	arg->sprites->grd = textures_init(arg, "textures/grass.xpm");
	arg->sprites->plr = textures_init(arg, "textures/cat.xpm");
	arg->sprites->ext = textures_init(arg, "textures/stairs.xpm");
	arg->sprites->obj = textures_init(arg, "textures/shrinp.xpm");
}

void	window(t_map *map, int ac, char **av)
{
	t_arg		*arg;

	arg = arg_init(map);
	arg->av = NULL;
	if (ac > 2)
	{
		arg->av = &av[1];
		arg->av[0] = av[0];
	}
	arg->frame->img = mlx_new_image(arg->mlx, map->len_line * 32,
			map->nbr_line * 32);
	if (!arg->frame->addr)
		exit(EXIT_FAILURE);
	arg->frame->addr = mlx_get_data_addr(arg->frame->img, &arg->frame->bpp,
			&arg->frame->line_len, &arg->frame->endian);
	arg->frame->path = NULL;
	arg_sprites_init(arg);
	if (!arg->frame->addr)
		ft_exit_failure(arg);
	map_to_window(arg);
	mlx_hook(arg->mlx_win, 17, 0, ft_exit_success, arg);
	mlx_key_hook(arg->mlx_win, key_hook, arg);
	mlx_loop(arg->mlx);
}
