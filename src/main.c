/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:57 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/11 16:43:42 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	mlx(void);

int main(int ac, char **av)
{
	char	*map_file = av[1];
	int 	i = 0;
	t_map 	*map;

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
	while (i < map->nbr_line)
	{
		printf("%s\n",map->map[i]);//temp test
		i++;
	}
	mlx();
	free_map(map);
}

void	mlx(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*path = "textures/test.xpm";
	int		img_width;
	int		img_height;

	(void)mlx_win;
	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "boop");
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}
