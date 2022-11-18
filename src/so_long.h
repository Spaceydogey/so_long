/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:02 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/18 18:23:04 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# else
#  include "../mlx/mlx.h"
# endif
# include "../libft/libft.h"
# include "../get_next_line/gnl.h"
# include <fcntl.h>
# include <unistd.h>
# define EMPTY '0'
# define WALL '1'
# define OBJ 'C'
# define EXIT 'E'
# define PLAYER 'P'

typedef struct s_obj
{
		int				x;
		int				y;
		struct s_obj	*next;
} t_obj;

typedef struct s_map
{
	int		nbr_line;
	int		len_line;
	int		nbr_exit;
	int		nbr_start;
	int		nbr_obj;
	int		error;
	char	**map;
	int		start_x;
	int		start_y;
} t_map;

typedef struct s_img
{
		void	*img;
		int		width;
		int		height;
		char	*addr;
		int		bpp;
		int		line_len;
		int		endian;
} t_img;

typedef struct s_player
{
		int 	x;
		int		y;
} t_player;

int		path_finding(int x, int y, t_map *map);
int moveright(t_player *player, t_map *map);
int moveleft(t_player *player, t_map *map);
int moveup(t_player *player, t_map *map);
int movedown(t_player *player, t_map *map);
t_player	*player_init(t_map *map);
char	*free_tab(char **tab, int nbr_line);
t_map	*parse_map(char *map_file);
int		file_error(char *map_file);
char	**map_realloc(char **p, size_t size_of, int *nbr_line);
void	free_table(void **p, int size);
char	*free_map(t_map *map);
int		map_error(t_map *map);
#endif
