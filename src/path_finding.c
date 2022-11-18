/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:17:50 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/18 18:54:16 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_obj_or_exit(char c, t_map *map)
{
	if (c == OBJ)
		map->nbr_obj -= 1;
	else if (c == EXIT)
		map->nbr_exit -= 1;
	if (map->nbr_obj == 0 && map->nbr_exit == 0)
		return (1);
	return (0);
}

int	path_finding(int x, int y, t_map *map)
{
	char	up;
	char	down;
	char	left;
	char	right;

	if (is_obj_or_exit(map->map[y][x], map) == 1)
		return (1);
	map->map[y][x] = '1';
	up = map->map[y - 1][x];
	down = map->map[y + 1][x];
	left = map->map[y][x - 1];
	right = map->map[y][x + 1];
	if (up == WALL && down == WALL && left == WALL && right == WALL)
		return (-1);
	if (up != WALL && up != '9')
		path_finding(x, y - 1, map);
	if (right != WALL && right != '9')
		path_finding(x + 1, y, map);
	if (left != WALL && left != '9')
		path_finding(x - 1, y, map);
	if (down != WALL && down != '9')
		path_finding(x, y + 1, map);
	if (is_obj_or_exit(map->map[y][x], map) == 1)
		return (1);
	return (0);
}
