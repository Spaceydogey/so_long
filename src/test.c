#include "so_long.h"
#include <stdio.h>




int main(int ac, char **av)
{
	char		*map_file = av[1];
	t_map 		*map;
	t_player	*player;

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
	player = player_init(map);
	print_map(map);
	printf("obj :%d, exit :%d\n",map->nbr_obj,map->nbr_exit);
	path_finding(player->x, player->y, map);
	print_map(map);
	printf("obj :%d, exit :%d\n",map->nbr_obj,map->nbr_exit);
	free(player);
	free_map(map);
}
