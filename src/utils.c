/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:02:07 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/18 10:57:54 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*free_tab(char **tab, int nbr_line)
{
	int	i;

	i = -1;
	while (++i < nbr_line)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	*free_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (map->map)
		free_tab(map->map, map->nbr_line);
	free(map);
	return (NULL);
}

void	map_info_cpy(t_map *res, t_map *map)
{
	res->nbr_line = map->nbr_line;
	res->len_line = map->len_line;
	res->nbr_exit = map->nbr_exit;
	res->nbr_start = map->nbr_start;
	res->nbr_obj = map->nbr_obj;
	res->error = map->error;
	res->start_x = map->start_x;
	res->start_y = map->start_y;
}

t_map	*map_dup(t_map *map)
{
	t_map	*res;
	int		i;

	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	map_info_cpy(res, map);
	res->map = malloc(sizeof(char *) * res->nbr_line);
	if (!res->map)
		return (NULL);
	i = -1;
	while (++i < res->nbr_line)
	{
		res->map[i] = ft_strdup(map->map[i]);
		if (!res->map[i])
		{
			res->nbr_line = i - 1;
			return ((t_map *)free_map(res));
		}
	}
	return (res);
}

char	**map_realloc(char **p, size_t size_of, int *nbr_line)
{
	char	**res;
	int		i;

	*nbr_line += 1;
	res = malloc(size_of * (*nbr_line + 1));
	if (!res)
		return (NULL);
	i = -1;
	if (p)
	{
		while (++i < *nbr_line - 1)
			res[i] = p[i];
	}
	res[*nbr_line - 1] = "\0";
	res[*nbr_line] = "\0";
	return (res);
}
