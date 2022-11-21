s:* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:10:02 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/21 20:22:24 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
int	key_hook(int keycode, t_arg *arg)
{
	int		i;

	i = 0;
//	printf("%d, %c\n", keycode, keycode);//temp test
	if (keycode == 13)
	{
		moveup(arg->player, arg->map);
		map_to_window(arg->mlx, arg->mlx_win, arg->map);
		while (i < arg->map->nbr_line)
		{
			printf("%s\n", arg->map->map[i]);//temp test
			i++;
		}
	}
	if (keycode == 1)
	{
		movedown(arg->player, arg->map);
		map_to_window(arg->mlx, arg->mlx_win, arg->map);
		while (i < arg->map->nbr_line)
		{
			printf("%s\n", arg->map->map[i]);//temp test
			i++;
		}
	}
	if (keycode == 2)
	{
		moveright(arg->player, arg->map);
		map_to_window(arg->mlx, arg->mlx_win, arg->map);
		while (i < arg->map->nbr_line)
		{
			printf("%s\n", arg->map->map[i]);//temp test
			i++;
			map_to_window(arg->mlx, arg->mlx_win, arg->map);
		}
	}
	if (keycode == 0)
	{
		moveleft(arg->player, arg->map);
		map_to_window(arg->mlx, arg->mlx_win, arg->map);
		while (i < arg->map->nbr_line)
		{
			printf("%s\n", arg->map->map[i]);//temp test
			i++;
		}
	}
	printf("%d\n", arg->player->is_on_exit);
	return (0);
}


