#include "so_long.h"
/*
static int	size_map(int fd)
{
	char	*line;
	int		nbr_line;

	line = get_next_line(fd);
	if (!line)
		return(-1);
	nbr_line = 0;
	while (line)
	{
		free(line);
		nbr_line += 1;
		line = get_next_line(fd);
	}
	free(line);
	return (nbr_line);
}*/

static char	*add_to_map(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strtrim(get_next_line(fd), "\n");
	while (line)
	{
		map->map = map_realloc(map->map, sizeof(char *),(size_t *)&map->nbr_line);
		map->map[i] = line;
		if (!map->map[i++])
		{
			map->nbr_line = i;
			return(NULL);
		}
		line = ft_strtrim(get_next_line(fd), "\n");
	}
	return (map->map[0]);
}

char	*free_map(t_map *map)
{
	int	i;

	i = -1;
	if (map->map)
	{
		while (++i < map->nbr_line)
			free(map->map[i]);
		free(map->map);
	}
	free(map);
	return (NULL);
}

static t_map	*init_map()
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->nbr_line = 0; 
	map->len_line = 0; 
	map->nbr_exit = 0; 
	map->nbr_start = 0; 
	map->nbr_obj = 0; 
	map->error = 0; 
	map->map = NULL;
	return (map);
}

t_map	*parse_map(char *map_file)
{
	t_map	*map;
	int 	fd;

	map = init_map();
/*	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return ((t_map *)free_map(map));
	map->nbr_line = size_map(fd);
	if (map->nbr_line <= 0)
		return ((t_map *)free_map(map));
	map->map = malloc(sizeof(char *) * (map->nbr_line + 1));
	if (!map->map)
		return ((t_map *)free_map(map));
	close(fd);*/
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return ((t_map *)free_map(map));
	if (!add_to_map(fd, map))
		return ((t_map *)free_map(map));
	map->len_line = ft_strlen(map->map[0]);
	close(fd);
	return (map);
}

