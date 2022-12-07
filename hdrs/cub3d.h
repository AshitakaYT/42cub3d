/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucousin <aucousin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:56:19 by aucousin          #+#    #+#             */
/*   Updated: 2022/12/07 16:31:36 by aucousin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include "../libft/hdrs/libft.h"
# include <sys/time.h>
# include <stdbool.h>

# define PI 3.14159
# define DR 0.0174533159
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define SIZE 12

// MACROS

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// structs

/* player position */
typedef struct s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	atan;
	float	ntan;
	float	dist_h;
	float	dist_v;
	float	dist_f;
	float	hx;
	float	hy;
	float	vx;
	float	vy;
	float	a;
}				t_player;

/* vector with an x and y */
typedef struct s_vector
{
	int	x;
	int	y;
	int	i;
	int	j;
}				t_vector;

/* all usable keys */
typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
}				t_keys;

/* A pointer to the window and its size */
typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color {
	int		r;
	int		g;
	int		b;
	int		a;
	char	*code;
	int		co;
}	t_color;

/* all info needed for an image */
typedef struct s_image {
	void			*img;
	t_vector		size;
	char			*addr;
	unsigned int	*intaddr;
	int				bits_per_pixel;
	int				line_size;
	int				endian;
	int				addrsize;
}				t_image;

/* elements : two colors and a path to an image */
typedef struct s_elem
{
	char	**elems;
	char	*so;
	char	*we;
	char	*no;
	char	*ea;
	char	*po;
	t_color	*fl;
	t_color	*ce;
}				t_elem;

/* a map in char** with it's width and its height. */
typedef struct s_map
{
	char		**tab;
	int			wid;
	int			hei;
	int			size;
	t_image		wall;
	t_image		floor;
	t_image		fps_banner;
	t_image		player;
	t_image		no;
	t_image		ea;
	t_image		we;
	t_image		so;
	t_image		po;
	t_player	*p;
}				t_map;

/* the main structure
strf is the path to the map info
tabf is the opended map*/
typedef struct s_cube
{
	float		frame1;
	float		frame2;
	float		fps;

	char		**map;
	char		*readfile;
	int			map_start;
	t_elem		*el;
	t_map		*ma;
	t_window	*win;
	void		*mlx;
	t_image		*img;
	int64_t		starting_time;
	int			grab_x;
	int			grab_y;
	int			is_grabing;
	int			last_mouse_x;

	int			key_forward;
	int			key_backward;
	int			key_strafe_left;
	int			key_strafe_right;
	int			key_open;

	float		ty_step;
	float		ty_offset;
	float		line_h;
	float		line_hlim;
	float		line_o;
	float		ca;
	int			r;
	int			type;

	int			key_rotate_right;
	int			key_rotate_left;

	int			display_map;
	int			key_display_map;
}				t_cube;

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

/* main.c */
/* parsing/check_elems.c */
char		*cube_check_elem(char **map, char *elem);
int			cube_atoi(char const *str, int *i);
int			cube_checkcolor(char *str);
int			cube_checkelems(t_cube *c);
/* parsing/check_map.c */
int			cube_checkmap_characters(char **map);
int			cube_checkmap_player(char **map);
int			cube_getmap(t_cube *c);
/* parsing/checkmap_closed.c */
int			cube_checkmap_closedfromleft(char **map);
int			cube_checkmap_closedfromright(char **map, int w);
int			cube_checkmap_closedfromtop(char **map, int w);
int			cube_checkmap_closedfrombot(char **map, int h, int w);
int			cube_checkclosedspaces(char **map);
/* parsing/checkmap_init.c */
int			cube_getmapwid(char **map);
char		**cube_fillmapwithspaces(char **tab, int w, int h);
int			cube_initmap(t_cube *c);
/* parsing/get_elems.c */
int			cube_getcolor(t_color *c, char *str);
int			cube_createcolors(t_cube *c);
void		cube_get_code(t_color *c, int color);
int			cube_get_color_code(t_color *c);
char		*cube_get_path(char *str);
int			cube_getcolor(t_color *c, char *str);
int			cube_getelems(t_cube *c);
/* parsing/parsing_main.c */
int			cube_openmap(t_cube *c, char *file);
int			cube_initparsing(t_cube *c);
int			cube_parsing(int ac, char **av, t_cube *c);
/* utils/print_cubeinfos.c */
void		cube_printelem(t_elem	*el);
void		cube_printmap(t_map	*map);
void		cube_print(t_cube c);
void		cube_printplayer(t_player *p);
/* visual/aucousin/visual_main.c*/
int			cube_mlx(t_cube *c);
int			ft_fps(t_cube *c);
int64_t		get_time(void);

/* visual/aucousin/window.c*/
int			ft_close(t_cube *c);
t_window	*ft_new_window(void *mlx, int widht, int height, char *name);
/* visual/aucousin/hooks.c */
int			cube_input(int key, void *param);
int			key_down(int key, t_cube *c);
int			key_up(int key, t_cube *c);

/* visual/aucousin/display2d.c */
int			cube_draw_vision(t_cube *c);
void		cube_minimap_print(t_cube *c, int i, int j);
void		cube_minimap(void *param);
/*
int 		draw_line(t_cube *c, void *win, int beginX,
		int beginY, int endX, int endY, int color);
*/
/* visual/aucousin/display3d.c */
void		cube_display_rays(t_cube *c);

/* visual/aucousin/image.c */
t_image		ft_new_image(void *mlx, int width, int height);
t_image		ft_new_sprite(void *mlx, char *path);
int			ft_create_sprites(t_cube *c);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);

/* visual/aucousin/display_walls3d.c*/
int			draw_wall(t_cube *c, int beginY, int endY, int color);
void		cube_draw_wall_cf(t_cube *c);
void		cube_draw_wall_n(t_cube *c, t_image t, int beginY, int endY);
void		cube_draw_wall_e(t_cube *c, t_image t, int beginY, int endY);
void		cube_draw_wall_s(t_cube *c, t_image t, int beginY, int endY);
void		cube_draw_wall_w(t_cube *c, t_image t, int beginY, int endY);

/* visual/aucousin/diplay_rays.c*/
void		cube_init_rays(t_cube *c);
void		cube_init_horizontal_rays(t_cube *c);
void		cube_horizontal_rays(t_cube *c);
void		cube_init_vertical_rays(t_cube *c);
void		cube_vertical_rays(t_cube *c);

/* visual/display_utils.c*/
int			draw_wall(t_cube *c, int beginY, int endY, int color);
float		cube_deg_to_rad(float a);
float		cube_distance2(float ax, float ay, float bx, float by);
float		cube_updatepi(float angle);
void		cube_compare_distance(t_cube *c);

void		cube_fps_print(t_cube *c, char *string);
int			ft_fps(t_cube *c);
int			mouse_pressed(int button, int x, int y, t_cube *c);
int			mouse_release(int button, int x, int y, t_cube *c);
int			mouse_moving(int x, int y, t_cube *c);

int			cube_mlx_init(t_cube *c);
int			cube_mlx_initplayer2(t_cube *c, int i, int j);
int			cube_mlx_initplayer(t_cube *c);

int			cube_free(t_cube *c);
void		ft_strfree(char *str);
/* Rgeral test*/
int64_t		get_time(void);
int			ft_fps(t_cube *c);
void		cube_3d(t_cube *c, int r);
void		cube_turn_right(t_cube *c);
void		cube_turn_left(t_cube *c);
int			straf_right(t_cube *c);
int			straf_left(t_cube *c);
void		cube_move_backward(t_cube *c);
void		cube_move_forward(t_cube *c);
void		cube_open_close_door(t_cube *c);
int			cube_checkmap_newline(char *str, char charset, int nb);

#endif