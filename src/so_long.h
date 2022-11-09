/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:02 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/08 17:11:12 by hdelmas          ###   ########.fr       */
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
	int	nbr_line;
	int	len_line;
	int	nbr_exit;
	int	nbr_start;
	int	nbr_obj;
	int	error;
	char	**map;
} t_map;

t_map	*parse_map(char *map_file);
char	*free_map(t_map *map);
#endif
