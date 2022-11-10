/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:57 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/10 11:54:34 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int ac, char **av)
{
	char	*map_file = av[1];
	(void) ac;
	int 	i = 0;
	t_map 	*map;
	
	if(file_error(map_file) != 0)
		return (-1);
	map = parse_map(map_file);
	if (map_error(map) != 0)
		return (-1);
	while (i < map->nbr_line)
	{
		printf("%s\n",map->map[i]);
		i++;
	}
	free_map(map);
}

