/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:57 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/22 11:50:46 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int ac, char **av)
{
	char	*map_file = av[1];
	int 	i = 0;
	t_map 	*map;
	t_map	*map_copy;
//	t_player	*player;

	if (ac > 2)
	{
		ft_putstr_fd("Error\nTo many arguments\n", 1);
		return (-1);
	}
	if(file_error(map_file) != 0)
		return (-1);
	map = parse_map(map_file);
	if (map_error(map) != 0)
	{
		free_map(map);
		return (-1);
	}
	map_copy = map_dup(map);
	if (map_copy == NULL)
	{
		free_map(map);
		return (-1);
	}
	if (has_path(map_copy) != 0)
	{
			free_map(map_copy);
			free_map(map);
			return (-1);
	}
	system("clear");
	while (i < map->nbr_line)
	{
		printf("%s\n",map->map[i]);//temp test
		i++;
	}
	window(map);
	//free(player);
	free_map(map_copy);
	free_map(map);
}






