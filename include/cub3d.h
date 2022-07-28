/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:29:54 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:38 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

# if defined(__linux__)
#  define FORWARD 122
#  define BACKWARD 115
#  define MOVE_LEFT 113
#  define MOVE_RIGHT 100
#  define ROTATE_LEFT 65361
#  define ROTATE_RIGHT 65363
#  define EXIT 65307
# else
#  define FORWARD 13
#  define BACKWARD 1
#  define MOVE_LEFT 0
#  define MOVE_RIGHT 2
#  define ROTATE_LEFT 123
#  define ROTATE_RIGHT 124
#  define EXIT 53
# endif

typedef struct sprite
{
	double	x;
	double	y;
	int		texture;
}	t_sprite;

typedef struct s_texture
{
	char	*path;
	void	*mlx_img;
	int		*addr;
	int		img_width;
	int		img_height;
	int		lenght;
	int		bit_per_pixel;
	int		endian;
}	t_texture;

typedef struct s_ray_data
{
	double		resolution_x;
	double		resolution_y;
	double		camera_x;
	double		plane_x;
	double		plane_y;
	double		dir_x;
	double		dir_y;
	double		raydir_x;
	double		raydir_y;
	double		pos_x;
	double		pos_y;
	int			map_x;
	int			map_y;
	double		ray_side_x;
	double		ray_side_y;
	double		ray_delta_x;
	double		ray_delta_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		walldistance;
	int			lineheight;	
	int			drawstart;	
	int			drawend;	
	int			color;
	double		rotate_left;
	double		rotate_right;
	int			texx;
	int			texy;
	int			text_select;
	double		wall_x;
	double		step;
	double		texpos;
	char		**map;
}	t_ray;

typedef struct s_key
{
	int	move_forward;
	int	move_back;
	int	move_left;
	int	move_right;
	int	rotate_left;
	int	rotate_right;
}	t_key;

typedef struct s_map
{
	char	**tab;
	int		width;
	int		height;
}	t_map;

typedef struct s_data
{
	void		*mlx_win;
	void		*mlx;
	t_texture	texture[8];
	int			floor;
	int			ceiling;
	void		*display;
	char		*display_add;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		player_spawn_dir;
	int			player_spawn_pos[2];
	int			edge_size;
	int			fov;
	int			shadding;
	int			resolution_x;
	int			resolution_y;
	double		move_speed;
	double		rotate_speed;
	t_ray		ray_data;
	t_key		key;
	int			keycode;
	int			textures_nb;
	int			fd;
	t_map		map;
	int			is_map_started;
}	t_data;

typedef struct s_map_data
{
	char	**map;
	int		x_start;
	int		y_start;
	int		pos_x;
	int		pos_y;
	int		width;
	int		height;
	char	dir;
	int		nb_pass;
	int		no_move_possible;
	int		is_againt_wall;
	int		nb_move;
}	t_map_data;

// render
int		ft_render_next_frame(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);
void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);

// texture
void	ft_calc_x_texture(t_data *data);
void	ft_choose_texture(t_ray *ray);
void	ft_calc_y_texture(t_data *data);
void	ft_print_texture(t_data *data, t_ray *ray, int x);

// wallcasting
void	ft_calc_ray_dir(t_ray *ray);
void	ft_calc_ray_delta(t_ray *ray);
void	ft_calc_rayside(t_ray *ray);
void	ft_launch_ray(t_ray *ray);
void	ft_calc_wall_distance(t_ray *ray);
void	ft_calc_wall_line(t_ray *ray);

// mini_map
void	ft_print_minimap(t_data *data, t_ray *ray);

// movements
void	ft_move_straight(t_ray *ray, t_data *data, t_key *key);
void	ft_move_right(t_ray *ray, t_data *data, t_key *key);
void	ft_move_left(t_ray *ray, t_data *data, t_key *key);
void	ft_rotate_right(t_ray *ray, t_data *data, t_key *key);
void	ft_rotate_left(t_ray *ray, t_data *data, t_key *key);
void	ft_movements(t_data *data);
double	ft_check_double_overflow(double value);

// hook
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);
int		ft_mouse(int x, int y, t_data *data);
void	ft_mouse_rotate_left(t_ray *ray, t_key *key);
void	ft_mouse_rotate_right(t_ray *ray, t_key *key);

// event
void	ft_event(t_ray *ray);
void	ft_use(t_data *data, t_ray *ray);

// floor
void	ft_floor_casting(t_data *data, t_ray *ray, int x);

// init
int		ft_init_data(t_data *data);
int		ft_init_display(t_data *data);
void	ft_init_direction(t_data *data, t_ray *ray);
void	ft_init_ray_data(t_data *data, t_ray *ray);
void	ft_init_texture(t_texture *tex, t_data *data);
int		ft_init_text(t_data *data);
void	ft_init_key(t_key *key);
int		ft_init_display(t_data *data);

// sprite
void	ft_sprite_casting(t_data *data, t_ray *ray, t_sprite *sprite);

/* PARSING */
int		ft_parsing(t_data *data);
void	ft_sub_fill_caract(char **caract, char *str);
int		ft_nb_section_split(char **line_splited);
void	ft_parse_color(int *color, char **tab);
int		ft_check_comma(char *str);
int		ft_check_miss_caract(t_data *data);

/* CHECKER */
int		ft_checker(int argc, char **argv, t_data *data);
int		ft_nb_section_split(char **line_splited);

/* CHECKER MAP */
void	ft_replace_space(t_data *data);
int		ft_check_out(t_map_data *d);
int		ft_move_is_valid(t_map_data *map_data, char *c);
void	ft_move(t_map_data *d, int move_against_wall);
int		ft_is_againt_wall(t_map_data *d);
int		ft_check_ext_wall(t_map_data *d);
int		ft_check_nb_move(t_map_data *d);
void	ft_set_dir_against_wall(t_map_data *d, int move_against_wall);
int		ft_is_againt_wall(t_map_data *d);
int		ft_follow_wall_left(t_map_data *d, int nb);
int		ft_follow_wall_right(t_map_data *d, int nb);
void	ft_rotate_dir_right(t_map_data *d);
void	ft_rotate_dir_left(t_map_data *d);
void	ft_sub_follow_wall_left(t_map_data *d);
void	ft_sub_follow_wall_right(t_map_data *d);

/* PREFER MOVE */
void	ft_sub_checker_chang_dir_l_n(t_map_data *d);
void	ft_sub_checker_chang_dir_l_w(t_map_data *d);
void	ft_sub_checker_chang_dir_l_s(t_map_data *d);
void	ft_sub_checker_chang_dir_l_e(t_map_data *d);
void	ft_sub_checker_chang_dir_r_n(t_map_data *d);
void	ft_sub_checker_chang_dir_r_w(t_map_data *d);
void	ft_sub_checker_chang_dir_r_s(t_map_data *d);
void	ft_sub_checker_chang_dir_r_e(t_map_data *d);

/* PARSING MAP */
void	ft_copy_map(char *line, t_data *data);
int		ft_map_begin(char *line);
int		ft_is_map_border(char *line);
int		ft_check_map(t_data *data);
void	ft_sub_fill_color(t_data *data, char *str1, char *str2, char *line);
void	ft_sub_fill_texture(t_data *data, char *str1, char *str2, char *line);

/* FREE */
int		ft_exit_game(t_data *data);
int		ft_free_texture(t_data *data);
void	ft_free_tab(char **tab);
void	ft_close_and_free(t_data *data);
void	ft_free_list(t_list *list);

/* DEBUG */
void	ft_printdata(t_data *data);
void	ft_print_map(t_map_data *data);
void	ft_printmap(t_data *data, char **map);

#endif
