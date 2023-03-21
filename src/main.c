/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:57 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/25 14:35:32 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*map_file;
	t_map	*map;

	map_file = av[1];
	if (file_error(map_file) != 0)
		return (-1);
	map = parse_map(map_file);
	if (!map)
	{
		ft_putstr_fd("Error\nEmpty file\n", 2);
		return (-1);
	}
	if (check_map(map) != 0)
		return (-1);
	window(map, ac, av);
	free_map(map);
}
