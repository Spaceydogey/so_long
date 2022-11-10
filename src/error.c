/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:41:17 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/10 11:51:19 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	char_test(t_map *map, char c)
{
	if (c == EMPTY || c == WALL)
		return ;
	else if (c == OBJ)
		map->nbr_obj += 1;
	else if (c == PLAYER)
		map->nbr_start += 1;
	else if (c == EXIT)
		map->nbr_exit += 1;
	else
		map->error += 1;
	return ;
}

static int	check_map_for_error(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->nbr_line)
	{
		if ((int)ft_strlen(map->map[i]) != map->len_line)
			return (-1);
		j = 0;
		if (i == 0 || i == map->nbr_line - 1)
		{
			while (map->map[i][j])
			{
				if (map->map[i][j] != WALL)
					return (-2);
				j++;
			}
		}
		else
		{
			if (map->map[i][0] != WALL || map->map[i][map->len_line - 1] != WALL)
				return (-2);
			while (map->map[i][j])
				char_test(map, map->map[i][j++]);
		}
	}
	return (0);
}

/*
int	has_path()
{

}
*/
int	file_error(char *map_file)
{
	int	len;

	if (!map_file)
	{
		ft_putstr_fd("Error\nNo map file\n", 1);
		return (-2);
	}
	len  = ft_strlen(map_file);
	if (ft_strncmp(&map_file[len - 4], ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nNot a .ber map file\n", 1);
		return (-1);
	}
	return (0);
}
int	map_error(t_map *map)
{
	char	*error_msg;
	int		check;

	if (!map)
	{
		ft_putstr_fd("Error\nEmpty map file or parsing error\n", 1);
		return (-1);
	}
	error_msg = NULL;
	check = check_map_for_error(map);
	if (check == -1)
		error_msg = "Map is not rectangular\n";
	else if (check == -2)
		error_msg = "Map is not closed\n";
	else if (map->nbr_start > 1 || map->nbr_start <= 0)
		error_msg = "The number of start tiles should be 1\n";
	else if (map->nbr_exit > 1 || map->nbr_exit <= 0)
		error_msg = "The number of exit tiles should be 1\n";
	else if (map->nbr_obj <= 0)
		error_msg = "The number of collectibles should at least be of 1\n";
	if (!error_msg)
		return (0);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(error_msg, 1);
	return(-1);
}
