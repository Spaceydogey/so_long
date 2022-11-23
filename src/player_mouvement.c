/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:14:16 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/23 17:12:34 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moveup(t_arg *arg)
{
	if (arg->map->map[arg->player->y - 1][arg->player->x] != WALL)
	{
		if (arg->map->map[arg->player->y - 1][arg->player->x] == OBJ)
		{
			arg->map->map[arg->player->y][arg->player->x] = '0';
			arg->map->nbr_obj -= 1;
		}
		else if (arg->map->map[arg->player->y - 1][arg->player->x] == EXIT)
		{
			arg->map->map[arg->player->y][arg->player->x] = '0';
			arg->player->is_on_exit = 1;
		}
		else if (arg->player->is_on_exit == 1)
		{
			arg->map->map[arg->player->y][arg->player->x] = EXIT;
			arg->player->is_on_exit = 0;
		}
		else
			arg->map->map[arg->player->y][arg->player->x] = '0';
		srpite_to_window(arg);
		arg->player->y -= 1;
		arg->map->map[arg->player->y][arg->player->x] = PLAYER;
		return (0);
	}
	return (-1);
}

int	movedown(t_arg *arg)
{
	if (arg->map->map[arg->player->y + 1][arg->player->x] != WALL)
	{
		if (arg->map->map[arg->player->y + 1][arg->player->x] == OBJ)
		{
			arg->map->map[arg->player->y][arg->player->x] = '0';
			arg->map->nbr_obj -= 1;
		}
		else if (arg->map->map[arg->player->y + 1][arg->player->x] == EXIT)
		{
			arg->map->map[arg->player->y][arg->player->x] = '0';
			arg->player->is_on_exit = 1;
		}
		else if (arg->player->is_on_exit == 1)
		{
			arg->map->map[arg->player->y][arg->player->x] = EXIT;
			arg->player->is_on_exit = 0;
		}
		else
			arg->map->map[arg->player->y][arg->player->x] = '0';
		srpite_to_window(arg);
		arg->player->y += 1;
		arg->map->map[arg->player->y][arg->player->x] = PLAYER;
		return (0);
	}
	return (-1);
}

int	moveleft(t_arg *arg)
{
	if (arg->map->map[arg->player->y][arg->player->x - 1] != WALL)
	{
		if (arg->map->map[arg->player->y][arg->player->x - 1] == OBJ)
		{
			arg->map->map[arg->player->y][arg->player->x] = '0';
			arg->map->nbr_obj -= 1;
		}
		else if (arg->map->map[arg->player->y][arg->player->x - 1] == EXIT)
		{
			arg->map->map[arg->player->y][arg->player->x] = '0';
			arg->player->is_on_exit = 1;
		}
		else if (arg->player->is_on_exit == 1)
		{
			arg->player->is_on_exit = 0;
			arg->map->map[arg->player->y][arg->player->x] = EXIT;
		}
		else
			arg->map->map[arg->player->y][arg->player->x] = '0';
		srpite_to_window(arg);
		arg->player->x -= 1;
		arg->map->map[arg->player->y][arg->player->x] = PLAYER;
		return (0);
	}
	return (-1);
}

int	moveright(t_arg *arg)
{
	if (arg->map->map[arg->player->y][arg->player->x + 1] != WALL)
	{
		if (arg->map->map[arg->player->y][arg->player->x + 1] == OBJ)
		{
			arg->map->map[arg->player->y][arg->player->x] = '0';
			arg->map->nbr_obj -= 1;
		}
		else if (arg->map->map[arg->player->y][arg->player->x + 1] == EXIT)
		{
			arg->map->map[arg->player->y][arg->player->x] = '0';
			arg->player->is_on_exit = 1;
		}	
		else if (arg->player->is_on_exit == 1)
		{
			arg->player->is_on_exit = 0;
			arg->map->map[arg->player->y][arg->player->x] = EXIT;
		}
		else
			arg->map->map[arg->player->y][arg->player->x] = '0';
		srpite_to_window(arg);
		arg->player->x += 1;
		arg->map->map[arg->player->y][arg->player->x] = PLAYER;
		return (0);
	}
	return (-1);
}
