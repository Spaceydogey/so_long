/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:14:16 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/18 13:34:21 by hdelmas          ###   ########.fr       */
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
		map->map[player->y][player->x] = '9';
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
		map->map[player->y][player->x] = '9';
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
		map->map[player->y][player->x] = '9';
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
		map->map[player->y][player->x] = '9';
		player->x += 1;
		map->map[player->y][player->x] = PLAYER;
		return (0);
	}
	return (-1);
}
