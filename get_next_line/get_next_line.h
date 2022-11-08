/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:28:41 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/08 13:42:57 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# if BUFFER_SIZE > 10000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*join_strdup(char *s, int *check);
void	ft_bzero(void *s, size_t n);
int		ft_len_to_add(char *str);
char	*add_to_line(char *res, char *remains, int *check, int fd);
char	*join_strjoin(char *s1, char *s2, int *check);
char	*get_next_line(int fd);

#endif
