/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:57 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/25 12:06:25 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*map_file;
	t_map	*map;
	int		i;

	i  = 1;
	//if (ac > 2)
//	{
//		ft_putstr_fd("Error\nTo many arguments\n", 1);
//		return (-1);
//	}
	while (i < ac)
	{
		map_file = av[i];
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
		window(map);
		free_map(map);
	}
}
