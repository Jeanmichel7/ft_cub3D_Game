/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:16:27 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_init_data(t_data *data)
{
	data->mlx_win = NULL;
	data->mlx = NULL;
	data->floor = -1;
	data->ceiling = -1;
	data->player_spawn_dir = 0;
	data->player_spawn_pos[0] = 0;
	data->player_spawn_pos[1] = 0;
	data->fov = 70;
	data->resolution_x = 1080;
	data->resolution_y = 720;
	data->move_speed = 0.05;
	data->rotate_speed = 0.05;
	data->keycode = -1;
	data->line_length = 0;
	data->bits_per_pixel = 0;
	data->keycode = 0;
	data->zbuffer = malloc(sizeof(double) * data->resolution_x);
	data->is_map_started = 0;
	data->map.height = 0;
	data->map.width = 0;
	data->map.tab = NULL;
	ft_init_texture(data);
	return (0);
}

void	ft_sub_init_direction(t_data *data, t_ray *ray)
{
	if (data->player_spawn_dir == 'W')
	{
		ray->dir_x = -1;
		ray->dir_y = 0;
		ray->plane_x = 0;
		ray->plane_y = -(double)data->fov / 100;
	}
	if (data->player_spawn_dir == 'E')
	{
		ray->dir_x = 1;
		ray->dir_y = 0;
		ray->plane_x = 0;
		ray->plane_y = (double)data->fov / 100;
	}
}

void	ft_init_direction(t_data *data, t_ray *ray)
{
	if (data->player_spawn_dir == 'S')
	{
		ray->dir_x = 0;
		ray->dir_y = 1;
		ray->plane_x = -(double)data->fov / 100;
		ray->plane_y = 0;
	}
	if (data->player_spawn_dir == 'N')
	{
		ray->dir_x = 0;
		ray->dir_y = -1;
		ray->plane_x = (double)data->fov / 100;
		ray->plane_y = 0;
	}
	ft_sub_init_direction(data, ray);
}

void	ft_init_ray_data2(t_ray *ray)
{
	ray->camera_x = 0;
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	ray->ray_side_x = 0;
	ray->ray_side_y = 0;
	ray->ray_delta_x = 0;
	ray->ray_delta_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->texx = 0;
	ray->texy = 0;
	ray->wall_x = 0;
	ray->step = 0;
	ray->texpos = 0;
	ray->ray_touch_door = 0;
	ray->size_door = 1;
	ray->pos_door_x = 0;
	ray->pos_door_y = 0;
	ray->door_before = 0;
	ray->case_count = 0;
}

void	ft_init_ray_data(t_data *data, t_ray *ray)
{
	ray->map = data->map.tab;
	ray->pos_x = data->player_spawn_pos[0] + 0.5 ;
	ray->pos_y = data->player_spawn_pos[1] + 0.5 ;
	ray->hit = 0;
	ray->side = 0;
	ray->color = 0x9B9B9B;
	ray->resolution_x = data->resolution_x;
	ray->resolution_y = data->resolution_y;
	ft_init_direction(data, ray);
	ft_init_ray_data2(ray);
	ray->door_open = 0;
	ray->pos_door_x = 0;
	ray->pos_door_y = 0;
	ft_init_key(&data->key);
}
