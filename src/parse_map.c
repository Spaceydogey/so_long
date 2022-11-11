/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:29:55 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/11 17:01:58 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*tmp_line;
	char	**tmp_map;

	i = 0;
	tmp_line = get_next_line(fd);
	if (!tmp_line)
		return (NULL);
	line = ft_strtrim(tmp_line, "\n");
	free(tmp_line);
	tmp_map = NULL;
	while (line)
	{
		map->map = map_realloc(tmp_map, sizeof(char *), &map->nbr_line);
		if (i == 3)
			map->map = NULL;
		if (!map->map)
		{
			map->nbr_line -= 1;
			map->map = tmp_map;
			return (NULL);//leaks if malloc fails add free tab might need temp var to be able to free all the lines 
		}
		free(tmp_map);
		map->map[i] = line;
		if (!map->map[i])
			return (NULL);
		i++;
		tmp_line = get_next_line(fd);
		line = ft_strtrim(tmp_line, "\n");
		free(tmp_line);
		tmp_map = map->map;
	}
	return ("good");
}

char	*free_map(t_map *map)
{
	int	i;

	i = -1;
	if (map->map)
		while (++i < map->nbr_line)
			free(map->map[i]);
	free(map->map);
	free(map);
	return (NULL);
}

static t_map	*init_map(void)
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
	int		fd;

	map = init_map();
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return ((t_map *)free_map(map));
	if (!add_to_map(fd, map))
		return ((t_map *)free_map(map));
	map->len_line = ft_strlen(map->map[0]);
	close(fd);
	return (map);
}
