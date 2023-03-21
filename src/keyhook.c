/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:10:02 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/25 14:27:37 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_arg *arg)
{
	int		check;
	char	*steps;

	check = -1;
	if (keycode == ESC)
		ft_exit_success(arg);
	if (keycode == W || keycode == UP)
		check = moveup(arg);
	if (keycode == S || keycode == DOWN)
		check = movedown(arg);
	if (keycode == D || keycode == RIGHT)
		check = moveright(arg);
	if (keycode == A || keycode == LEFT)
		check = moveleft(arg);
	if (check == -1)
		return (-1);
	sprite_to_window(arg);
	arg->player->steps += 1;
	steps = ft_itoa(arg->player->steps);
	ft_putendl_fd(steps, 1);
	mlx_string_put(arg->mlx, arg->mlx_win, 3, 10, 16711680, steps);
	free(steps);
	if (arg->player->is_on_exit == 1 && arg->map->nbr_obj == 0)
		ft_next(arg);
	return (0);
}
