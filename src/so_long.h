/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:02 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/21 18:37:24 by hdelmas          ###   ########.fr       */
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
# include <stdlib.h>
# define EMPTY '0'
# define WALL '1'
# define OBJ 'C'
# define EXIT 'E'
# define PLAYER 'P'
typedef unsigned int uint;

typedef struct s_obj
{
	int				x;
	int				y;
}	t_obj;

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
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_textures
{
	t_img	wll;
	t_img	grd;
	t_img	plr;
	t_img	ext;
	t_img	obj;
}	t_textures;

typedef struct s_cp_pixel
{
	int		y_sp;
	int		x_sp;
	int		x_fr;
	int		y_fr;
}	t_cp_pixel;

typedef struct s_player
{
	int		x;
	int		y;
	int		steps;
	int		is_on_exit;
}	t_player;

typedef struct	s_arg
{
	t_map		*map;
	t_player	*player;
	void		*mlx;
	void		*mlx_win;
}	t_arg;

int			key_hook(int keycode, t_arg *arg);
int			has_path(t_map *map);
void		map_to_window(void *mlx, void *mlx_win, t_map *map);
void		window(t_map *map);
int			path_finding(int x, int y, t_map *map);
t_map		*map_dup(t_map *map);
int			moveright(t_player *player, t_map *map);
int			moveleft(t_player *player, t_map *map);
int			moveup(t_player *player, t_map *map);
int			movedown(t_player *player, t_map *map);
t_player	*player_init(t_map *map);
char		*free_tab(char **tab, int nbr_line);
t_map		*parse_map(char *map_file);
int			file_error(char *map_file);
char		**map_realloc(char **p, size_t size_of, int *nbr_line);
void		free_table(void **p, int size);
char		*free_map(t_map *map);
int			map_error(t_map *map);

#endif
