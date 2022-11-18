#include "so_long.h"
#include <stdio.h>


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
int	is_obj_or_exit(char  c, t_map *map)
{
	if (c == OBJ)
		map->nbr_obj -= 1;
	else if (c == EXIT)
		map->nbr_exit -= 1;
	if (map->nbr_obj == 0 && map->nbr_exit == 0)
		return (1);
	return (0);
}
int		path_finding(int x, int y, t_map *map)
{
	char	up;
	char	down;
	char	left;
	char	right;
	
	if (is_obj_or_exit(map->map[y][x], map) == 1)
		{
			printf("obj :%d, exit :%d\n",map->nbr_obj,map->nbr_exit);
			print_map(map);
			return (1);
		}
	print_map(map);
	map->map[y][x] = '9';
	up = map->map[y - 1][x];
	down =  map->map[y + 1][x];
	left = map->map[y][x - 1]; 
	right = map->map[y][x + 1];
	if (up == WALL && down == WALL && left == WALL && right == WALL)
		return (-1);
	if (up != WALL && up != '9')
		path_finding(x, y - 1, map);
	if (right != WALL && right != '9')
		path_finding(x + 1, y, map);
	if (left != WALL && left != '9')
		path_finding(x - 1, y, map);
	if (down != WALL && down != '9')
		path_finding(x, y + 1, map);
	return(0);
}

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
	free(player);
	free_map(map);
}
