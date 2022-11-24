/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:17:50 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 17:34:01 by hdelmas          ###   ########.fr       */
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

static void	rec(int x, int y, t_map *map)
{
	path_finding(x, y, map);
	map->map[y][x] = '9';
}

static int	pf_check(int x, int y, t_map *map)
{	
	char	up;
	char	down;
	char	left;
	char	right;

	map->map[y][x] = '9';
	up = map->map[y - 1][x];
	down = map->map[y + 1][x];
	left = map->map[y][x - 1];
	right = map->map[y][x + 1];
	if (up == WALL && down == WALL && left == WALL && right == WALL)
		return (-1);
	if (up != WALL && up != '9')
		rec(x, y - 1, map);
	right = map->map[y][x + 1];
	if (right != WALL && right != '9')
		rec(x + 1, y, map);
	left = map->map[y][x - 1];
	if (left != WALL && left != '9')
		rec(x - 1, y, map);
	down = map->map[y + 1][x];
	if (down != WALL && down != '9')
		rec(x, y + 1, map);
	return (1);
}

//stack overflow on big map ???
int	path_finding(int x, int y, t_map *map)
{
	if (is_obj_or_exit(map->map[y][x], map) == 1)
		return (1);
	if (pf_check(x, y, map) == -1)
		return (-1);
	if (is_obj_or_exit(map->map[y][x], map) == 1)
		return (1);
	return (0);
}
