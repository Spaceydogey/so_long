/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:29:55 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/18 09:21:34 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*gnl_trim(int fd)
{
	char	*line;
	char	*tmp_line;

	tmp_line = get_next_line(fd);
	if (!tmp_line)
		return (NULL);
	line = ft_strtrim(tmp_line, "\n");
	free(tmp_line);
	if (!line)
		return (NULL);
	return (line);
}

static char	*add_to_map(int fd, t_map *map)
{
	int		i;
	char	*line;
	char	**tmp_map;

	i = 0;
	line = gnl_trim(fd);
	if (!line)
		return (NULL);
	tmp_map = NULL;
	while (line)
	{
		map->map = map_realloc(tmp_map, sizeof(char *), &map->nbr_line);
		if (!map->map)
		{
			free(line);
			return (free_tab(tmp_map, map->nbr_line - 1));
		}
		free(tmp_map);
		map->map[i++] = line;
		line = gnl_trim(fd);
		tmp_map = map->map;
	}
	return ("good");
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
	map->start_x = 0;
	map->start_y = 0;
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
