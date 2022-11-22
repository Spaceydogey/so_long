/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:10:02 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/22 16:20:13 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
int	key_hook(int keycode, t_arg *arg)
{
	int	check;

	check = -1;
//	printf("%d, %c\n", keycode, keycode);//temp test
	if (keycode == ESC || (arg->player->is_on_exit == 1 && arg->map->nbr_obj == 0))
	{
	//	system("leaks so_long");
		exit(EXIT_SUCCESS);
	}
	if (keycode == W || keycode == UP)
		check = moveup(arg->player, arg->map);
	if (keycode == S || keycode == DOWN)
		check = movedown(arg->player, arg->map);
	if (keycode == D || keycode == RIGHT)
		check = moveright(arg->player, arg->map);
	if (keycode == A || keycode == LEFT)
		check = moveleft(arg->player, arg->map);
	if (check == -1)
		return (-1);
	arg->player->steps += 1;
	ft_putnbr_fd(arg->player->steps, 1); 
	ft_putchar_fd('\n', 1); 
	map_to_window(arg);
	return (0);
}
