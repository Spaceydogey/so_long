/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:57 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/08 17:00:35 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(void)
{
	char	*map_file = "maps/test_map.ber";
	int 	i = 0;
	char 	**map;
	
	map = parse_map(map_file);
	while (i < 5)
	{
		printf("%s",map[i]);
		i++;
	}
	free_map(map);
}

