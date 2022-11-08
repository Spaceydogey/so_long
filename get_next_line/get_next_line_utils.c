/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:30:21 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/08 13:38:08 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = -1;
	srclen = -1;
	while (src[++srclen])
		;
	if (dstsize == 0)
		return (srclen);
	while (++i < dstsize - 1 && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (srclen);
}

char	*join_strdup(char *s, int *check)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = -1;
	while (s[len])
	{
		if (s[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (++i < len)
		res[i] = s[i];
	res[i] = '\0';
	if (len > 0 && res[i - 1] == '\n')
		*check = i - 1;
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	char			*res;

	if (n == 0)
		return ;
	i = -1;
	res = s;
	while (++i < n)
		res[i] = '\0';
	return ;
}

char	*join_strjoin(char *s1, char *s2, int *check)
{
	char	*strjoin;
	int		i;
	int		j;
	int		len_join;

	len_join = ft_strlen(s1) + ft_strlen(s2);
	strjoin = malloc(sizeof(char) * (len_join + 1));
	if (!strjoin)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = -1;
	while (s1[++j])
		strjoin[i++] = s1[j];
	free(s1);
	j = -1;
	while (s2[++j])
		strjoin[i++] = s2[j];
	strjoin[i] = '\0';
	if (len_join > 0 && strjoin[i - 1] == '\n')
		*check = 0;
	return (strjoin);
}
