/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:17:50 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 16:30:12 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
/*
void	print_map(t_map *map)
{
	int 		i = 0;
	int			j;
	char		c;

	while (i < map->nbr_line)
	{
		j = 0;
		while (j < map->len_line)
		{
			c = map->map[i][j];
			if (c == PLAYER)
				printf("\033[0;34m%c",c);//temp test
			else if (c == '9')
				printf("\033[0;31m%c",c);//temp test
			else if (c == OBJ)
				printf("\033[0;32m%c",c);//temp test
			else if (c == EXIT)
				printf("\033[0;33m%c",c);//temp test
			else
				printf("\033[0m%c",c);//temp test
			j++;
		}
		printf("\n");//temp test
		i++;
	}
}
*/
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

static int	pf_check(int x, int y, t_map *map)
{	
	char	up;
	char	down;
	char	left;
	char	right;
//	system("clear");
//	usleep(10000);
	map->map[y][x] = '9';
	up = map->map[y - 1][x];
	down = map->map[y + 1][x];
	left = map->map[y][x - 1];
	right = map->map[y][x + 1];
//	print_map(map);
	if (up == WALL && down == WALL && left == WALL && right == WALL)
		return (-1);
//	printf("up :%c\n",up);
	if (up != WALL && up != '9')
	{
		path_finding(x, y - 1, map);
		map->map[y - 1][x] = '9';
	}
	right = map->map[y][x + 1];
//	printf("right :%c\n",right);
	if (right != WALL && right != '9')
	{
		path_finding(x + 1, y, map);
		map->map[y][x + 1] = '9';
	}
	left = map->map[y][x - 1];
//	printf("lft :%c\n",left);
	if (left != WALL && left != '9')
	{
		path_finding(x - 1, y, map);
		map->map[y][x - 1] = '9';
	}
	down = map->map[y + 1][x];
//	printf("down :%c\n",down);
	if (down != WALL && down != '9')
	{
		path_finding(x, y + 1, map);
		map->map[y + 1][x] = '9';
	}
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
