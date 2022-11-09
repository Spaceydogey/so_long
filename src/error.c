#include "so_long.h"

static void	char_test(t_map *map, char c)
{
	if (c == EMPTY || c == WALL)
		return ;
	else if (c == OBJ)
		map->nbr_obj += 1;
	else if (c == PLAYER)
		map->nbr_start += 1;
	else if (c == EXIT)
		map->nbr_exit += 1;
	else
		map->error += 1;
	return ;
}

static int	check_map_for_error(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	
	while (map->map[++i])
	{
		if (ft_strlen(map->map[i]) != map->len_line)
				return (-1);
		j = 0;
		else if (i == 0 || i == map->nbr_line - 1)
			while (map->map[i][j])
				if (map->map[i][j++] != 1)
					return (-2);
		else
		{
			if (map->map[i][0] != 1 || map->map[i][map->len_line - 1] != 1)
				return (-2);	
			while (map->map[i][j])
				char_test(map, map->map[i][j]);			
		}
	}
	return (0);
}
/*
int	has_path()
{

}
*/
int	map_error(t_map map)
{
}
