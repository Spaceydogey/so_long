/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:02:07 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/10 17:39:45 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_realloc(char **p, size_t size_of, size_t *nbr_line)
{
	char	**res;

	if (!p)
		return (NULL);
	*nbr_line += 1;
	res = malloc(size_of * (*nbr_line + 1));
	if (!res)
		return (NULL);
	ft_memmove((void *)res, (void *)p, (unsigned long)nbr_line);
	free(p);
	res[(int)nbr_line] = "\0";
	return (res);
}

