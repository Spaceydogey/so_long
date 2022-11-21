/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:14:16 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/21 20:22:22 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*player_init(t_map *map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x = map->start_x;
	player->y = map->start_y;
	return (player);
}

int	moveup(t_player *player, t_map *map)
{
	if (map->map[player->y - 1][player->x] != WALL)
	{
		if (map->map[player->y - 1][player->x] == OBJ)
		{
			map->map[player->y][player->x] = '0';
			map->nbr_obj -= 1;
		}
		else if (map->map[player->y - 1][player->x] == EXIT)
		{
			map->map[player->y][player->x] = '0';
			if (map->nbr_obj == 0)
				exit(1);
			else
				player->is_on_exit = 1;
		}
		else if (player->is_on_exit == 1)
		{
			map->map[player->y][player->x] = EXIT;
			player->is_on_exit = 0;
		}
		else
			map->map[player->y][player->x] = '0';
		player->y -= 1;
		map->map[player->y][player->x] = PLAYER;
		return (0);
	}
	return (-1);
}

int	movedown(t_player *player, t_map *map)
{
	if (map->map[player->y + 1][player->x] != WALL)
	{
		if (map->map[player->y + 1][player->x] == OBJ)
		{
			map->map[player->y][player->x] = '0';
			map->nbr_obj -= 1;
		}
		else if (map->map[player->y + 1][player->x] == EXIT)
		{
			map->map[player->y][player->x] = '0';
			if (map->nbr_obj == 0)
				exit(1);
			else
				player->is_on_exit = 1;
		}
		else if (player->is_on_exit == 1)
		{
			map->map[player->y][player->x] = EXIT;
			player->is_on_exit = 0;
		}
		else
			map->map[player->y][player->x] = '0';
		player->y += 1;
		map->map[player->y][player->x] = PLAYER;
		return (0);
	}
	return (-1);
}

int	moveleft(t_player *player, t_map *map)
{
	if (map->map[player->y][player->x - 1] != WALL)
	{
		if (map->map[player->y][player->x - 1] == OBJ)
		{
			map->map[player->y][player->x] = '0';
			map->nbr_obj -= 1;
		}
		else if (map->map[player->y][player->x - 1] == EXIT)
		{
			map->map[player->y][player->x] = '0';
			if (map->nbr_obj == 0)
				exit(1);
			else
				player->is_on_exit = 1;
		}
		else if (player->is_on_exit == 1)
		{
			player->is_on_exit = 0;
			map->map[player->y][player->x] = EXIT;
		}
		else
			map->map[player->y][player->x] = '0';
		player->x -= 1;
		map->map[player->y][player->x] = PLAYER;
		return (0);
	}
	return (-1);
}

int	moveright(t_player *player, t_map *map)
{
	if (map->map[player->y][player->x + 1] != WALL)
	{
		if (map->map[player->y][player->x + 1] == OBJ)
		{
			map->map[player->y][player->x] = '0';
			map->nbr_obj -= 1;
		}
		else if (map->map[player->y][player->x + 1] == EXIT)
		{
			map->map[player->y][player->x] = '0';
			map->map[player->y][player->x] = PLAYER;
			if (map->nbr_obj == 0)
				exit(1);
			else
			player->is_on_exit = 1;
		}
		else if (player->is_on_exit == 1)
		{
			player->is_on_exit = 0;
			map->map[player->y][player->x] = EXIT;
		}
		else
			map->map[player->y][player->x] = '0';
		player->x += 1;
		map->map[player->y][player->x] = PLAYER;
		return (0);
	}
	return (-1);
}
