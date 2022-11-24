/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:02 by hdelmas           #+#    #+#             */
/*   Updated: 2022/11/24 10:31:20 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifdef __linux__
#  include "../mlx_linux/mlx.h"
#  define W 119
#  define S 115
#  define D 100
#  define A 97
#  define UP 65362
#  define RIGHT 65363
#  define DOWN 65364
#  define LEFT 65361
#  define ESC 65307   
# else
#  include "../mlx/mlx.h"
#  define W 13
#  define S 1
#  define D 2
#  define A 0
#  define UP 126
#  define RIGHT 124
#  define DOWN 125
#  define LEFT 123
#  define ESC 53
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

typedef unsigned int	t_uint;

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

typedef struct s_pixel
{
	int		x_fr;
	int		y_fr;
}	t_pixel;

typedef struct s_player
{
	int		x;
	int		y;
	int		steps;
	int		is_on_exit;
}	t_player;

typedef struct s_arg
{
	t_map		*map;
	t_player	*player;
	void		*mlx;
	void		*mlx_win;
	t_textures	*sprites;
	t_img		*frame;
}	t_arg;

int			check_map(t_map *map);
void		sprite_to_window(t_arg *arg);
void		pixel_texture_to_frame(t_arg *arg, t_textures *sprite,
				t_img *frame, t_pixel pxl);
void		destroy_image(void *mlx, t_textures *sprites);
int			key_hook(int keycode, t_arg *arg);
int			has_path(t_map *map);
void		map_to_window(t_arg *arg);
void		window(t_map *map);
int			path_finding(int x, int y, t_map *map);
t_map		*map_dup(t_map *map);
int			moveright(t_arg *arg);
int			moveleft(t_arg *arg);
int			moveup(t_arg *arg);
int			movedown(t_arg *arg);
char		*free_tab(char **tab, int nbr_line);
t_map		*parse_map(char *map_file);
int			file_error(char *map_file);
char		**map_realloc(char **p, size_t size_of, int *nbr_line);
void		free_table(void **p, int size);
char		*free_map(t_map *map);
int			ft_exit(t_arg *arg);
int			map_error(t_map *map);

#endif
