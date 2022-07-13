/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:29:54 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/13 23:53:50 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_mac/mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_map
{
	char	**tab;
	int		width;
	int		height;
}	t_map;

typedef struct ray_data
{
	double	resolution_x; 
	double	resolution_y; 
	double	camera_x;
	double	plane_x; // vecteur plan camera
	double	plane_y;
	double	dir_x; // vecteur du regard du joueur
	double	dir_y; 
	double	raydir_x; // vecteur rayon lanceé pour detecter un mur
	double	raydir_y; 
	double	pos_x;	// position du joueur 
	double	pos_y;
	int		map_x; // position du carre dans lequel est le joueur sur la carte
	int		map_y; 
	double	side_x; //distance a parcourir avant la premiere intersection de la position du joueur 
	double	side_y;
	double	delta_x;// distance a parcourir avant une intersection 
	double	delta_y;
	int		step_x; // sens du rayon ( positif ou negatif ) x
	int		step_y; // sens du rayon ( positif ou negatif ) y
	int		hit;	// indique si un mur a ete touche 
	int		side;
	int		walldistance; // distance du rayon jusqu au mur
	int		lineheight; // hauteur de la ligne de pixel 
	int		drawstart; // debut de la ligne de pixel 
	int		drawend;  // fin de la ligne de pixel 
	int		color; 
	char	 **map;
}	t_ray;

typedef struct s_data
{
	void	*mlx_win;
	void	*mlx;
	char	*texture_N;
	char	*texture_S;
	char	*texture_W;
	char	*texture_E;
	int		color_floor; 			//color
	int		color_ceiling;			//color
	//char	**map;
	int		fd;
	void	*display;			// ray casting
	char	*display_add;		// ray casting
	int		bits_per_pixel; 	// on verra...
	int		line_length;		// mlx_get_data_addr
	int		endian;				// mlx_get_data_addr

	char	player_spawn_dir;
	int		player_spawn_x;
	int		player_spawn_y;
	int		fov; 
	int		resolution_x;
	int		resolution_y;
	t_map	map;
	int		is_map_started;
	t_ray	ray_data; 
}	t_data;

typedef	struct s_map_data
{
	char	**map;
	int		x_start;
	int		y_start;
	int		posX;
	int		posY;
	int		width;
	int		height;
	char	dir;
	int		nb_pass;
}	t_map_data;


/* MAIN */
void	ft_init_data(t_data *data);
void	ft_init_display(t_data *data);


/* CHECKER */
int		ft_checker(int argc, char **argv, t_data *data);
int		ft_nb_section_split(char **line_splited);

/* PARSING */
int 	ft_parsing(t_data *data);
void	ft_sub_fill_caract(char **caract, char *str);
int		ft_nb_section_split(char **line_splited);
void	ft_parse_color(int *color, char **tab);
int		ft_check_comma(char	*str);

/* PASRING MAP */
void	ft_copy_map(char *line, t_data *data);
int		ft_map_begin(char *line);
int		ft_is_map_border(char *line);
int		ft_check_map(t_data *data);
int		ft_follow_wall(t_map_data *d);

/* CHECKER MAP */
int		ft_check_out(t_map_data *d);
int		ft_move_is_valid(char c);
void	ft_move(t_map_data *d);

/* FREE */
int		ft_free_texture(t_data *data);
void	ft_free_tab(char **tab);
void	ft_close_and_free(t_data *data);

/* DEBUG */
void	ft_printdata(t_data *data);
void	ft_print_map(t_map_data *data);

#endif