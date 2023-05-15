/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:08:02 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 01:49:11 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FALSE 0
# define TRUE 1
# define TEX_HEIGHT 64
# define TEX_WIDTH 64
# define EMPTY_LINE '\0'
# define MAP_START -1
# define PI 3.1415926535897

# define PARAMS					6
# define C_NO					0
# define C_SO					1
# define C_EA					2
# define C_WE					3
# define C_F 					4
# define C_C					5

# define EVENT_KEY_PRESS		2
# define EVENT_KEY_EXIT		17

# define KEY_ESC		53
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_W		13
# define KEY_A		0
# define KEY_D		2
# define KEY_S		1

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define EMPTY '0'
# define WALL '1'

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

typedef struct	s_ray
{
	double		camerax;
	double		dirx;
	double		diry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			texnum;
	double		wallx;
	int			texx;
	double		step;
	double		texpos;
	int			texy;
}				t_ray;

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_tex
{
	char		*path[6];
	int			tile[6][TEX_WIDTH * TEX_HEIGHT];
	int			floor;
	int			ceiling;
	int			twidth;
	int			theight;
}				t_tex;

typedef struct	s_setup
{
	int			param[PARAMS];
	int			res_width;
	int			res_height;
	t_tex		tex;
	char		**map;
	int			map_width;
	int			map_height;
}				t_setup;

typedef struct	s_player
{
	double		posx;
	double		posy;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	char		dir;
}				t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_setup		setup;
	t_player	player;
	int			**buf;
	double		*n_buffer;
	int			fd;
	char		*line;
	t_list		*lst;
	t_ray		ray;
	t_img		img;
}				t_game;

//error.c
int			ft_error(char *str);
int	ft_error_2(t_game *game, char *str, int code);
void	exit_game(t_game *game, char *str, int code);
void	ft_free_tab(char **str);
//cub3d.c
void			check_argument(int argc);
//param.c
void			open_cub(t_game *game, char *filename);
int				check_param(t_game *game, char *info);
void			read_info(t_game *game);
void			validate_info(t_game *game);
// init.c
void			init_setup(t_game *game);
void			init_player(t_game *game, int i, int j);
// parse_setup.c
void			parse_resolution(t_game *game, char *line, int flag);
void			parse_texture(t_game *game, char *filename, int flag);
void			parse_color(t_game *game, char *line, int flag);
// get_next_line.c
int				get_next_line2(int fd, char **line);
// map.c
void			read_map(t_game *game, char *line);
void			allocate_map(t_game *game, t_list *curr);
void			store_map_as_array(t_game *game, t_list *curr);
// parce_map.c
void			validate_map(t_game *game);
void			validate_map_horizontal(t_game *game,char **map, int width, int height);
void			validate_map_vertical(t_game *game,char **map, int width, int height);
// run.c
void			run_game(t_game *game);
int				main_loop(t_game *game);
void			render(t_game *game);
void			raycast(t_game *game);
void			raycast_sprite(t_game *game, t_player *player);
//key.c
int				key_exit(void *param);
int				key_press(int keycode, t_game *game);
//move.c
void			move_front_back(t_game *game, double move_speed);
void			move_left_right(t_game *game, double move_speed);
void			rotate_player(t_player *player, double rot);
//raycast.c
void			init_ray(t_game *game, t_player *player, t_ray *ray, int x);
void			calculate_step(t_player *player, t_ray *ray);
void			perform_dda(t_setup *setup, t_ray *ray);
void			calculate_wall_distance(t_player *player, t_ray *ray);
void			calculate_wall_height(t_game *game, t_ray *ray);
//texture.c
void			set_ceiling_floor(t_game *game);
void			set_wall_tex(t_player *player, t_ray *ray);
void			set_wall_color(t_game *game, t_ray *ray, int i);
// utils.c
int				ft_isset(char c, char *str);
int				ft_long_cont_lst(t_list *lst);
int				check_color(char **buf, int i);
int				str_isdigit(char *str);
int				check_argcolor(char *line);
// check_all_setup.c
int				check_all_setup(t_game *game);
void			set_orient_player(t_game *game);
void			allocate_buffer(t_game *game);
void			load_texture(t_game *game);
void			load_image(t_game *game, int *texture, char *path, t_img *img);


#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 16
#endif
