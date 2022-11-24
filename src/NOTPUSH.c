/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NOTPUSH.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:58:21 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 10:00:23 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

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
