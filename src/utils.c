/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:02:07 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/11 16:56:13 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_realloc(char **p, size_t size_of, int *nbr_line)
{
	char	**res;
	int		i;

	*nbr_line += 1;
	res = malloc(size_of * (*nbr_line + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < *nbr_line - 1)
		res[i] = p[i];
	res[*nbr_line - 1] = "\0";
	res[*nbr_line] = "\0";
	return (res);
}
