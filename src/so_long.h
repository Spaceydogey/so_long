/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:02 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/11 15:49:55 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../get_next_line/gnl.h"
# include <fcntl.h>
# include <unistd.h>
# define EMPTY '0'
# define WALL '1'
# define OBJ 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct s_map
{
	int		nbr_line;
	int		len_line;
	int		nbr_exit;
	int		nbr_start;
	int		nbr_obj;
	int		error;
	char	**map;
} t_map;

char	*free_tab(char **tab, int nbr_line);
t_map	*parse_map(char *map_file);
int		file_error(char *map_file);
char	**map_realloc(char **p, size_t size_of, int *nbr_line);
void	free_table(void **p, int size);
char	*free_map(t_map *map);
int		map_error(t_map *map);
#endif
