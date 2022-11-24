/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:10:02 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 11:45:36 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_arg *arg)
{
	int	check;

	check = -1;
	if (keycode == ESC
		|| (arg->player->is_on_exit == 1 && arg->map->nbr_obj == 0))
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
	ft_putnbr_fd(arg->player->steps, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
