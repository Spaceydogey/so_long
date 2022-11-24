/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:57 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 10:36:18 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*map_file;
	t_map	*map;

	if (ac > 2)
	{
		ft_putstr_fd("Error\nTo many arguments\n", 1);
		return (-1);
	}
	map_file = av[1];
	if (file_error(map_file) != 0)
		return (-1);
	map = parse_map(map_file);
	if (check_map(map) != 0)
		return (-1);
	window(map);
	free_map(map);
}
