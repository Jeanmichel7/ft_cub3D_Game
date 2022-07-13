/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:31:47 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/12 18:05:38 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst; 

	dst = data->display_add + (y * data->line_length + x * (data->bits_per_pixel / 8)); 
	*(unsigned int*)dst = color; 
}

// calcul of ray vector
int	ft_render_next_frame(t_data *data)
{
	int	x;
	t_ray *ray;
	ray = &data->ray_data;

	x = 0;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	while (x < ray->resolution_x)
	{
		ray->camera_x = 2 * x / ray->resolution_x - 1;
		ray->raydir_x =	ray->dir_x + ray->plane_x * ray->camera_x;
		ray->raydir_y =	ray->dir_y + ray->plane_y * ray->camera_x;
		if (ray->raydir_x == 0)
			ray->dir_x = exp(30);
		if (ray->dir_y == 0)
			ray->raydir_y = exp(30);
		ray->delta_y = sqrt(1 + ((ray->raydir_x * ray->raydir_x ) / ( ray->raydir_y * ray->raydir_y))); // distance a parcourir pour aller a l'intersection suivante
		ray->delta_x = sqrt(1 + ((ray->raydir_y * ray->raydir_y ) / ( ray->raydir_x * ray->raydir_x)));
		if (ray->raydir_x < 0)
		{
			ray->step_x = -1;
			ray->side_x = (ray->pos_x - ray->map_x) * ray->delta_x; 
		}
		else
		{
			ray->step_x = 1;
			ray->side_x = (ray->map_x + 1 - ray->pos_x) * ray->delta_x; 
		}
		if (ray->raydir_y < 0)
		{
			ray->step_y = -1;
			ray->side_y = (ray->pos_y - ray->map_y) * ray->delta_y; 
		}
		else
		{
			ray->step_y = 1;
			ray->side_y = (ray->map_y + 1 - ray->pos_y) * ray->delta_y; 
		}
		while (ray->hit == 0) 
		{
			if (ray->side_x < ray->side_y)
			{
				ray->side_x += ray->delta_x; 
				ray->map_x += ray->step_x; 
				ray->side = 0;               
			}
			else 
			{
				ray->side_y += ray->delta_y;
				ray->map_y += ray->step_y; 
				ray->side = 1;
			}
			if (ray->map[ray->map_y][ray->map_x] == '1')
				ray->hit = 1; 
		}
		if (ray->side == 0)
			ray->walldistance = (ray->side_x - ray->delta_x); // on prend la distance dx car c'est le rayon x qui a connecte au mur en premier
		else 
			ray->walldistance = (ray->side_y - ray->delta_y); // come on est un carre trop loin il faut enlever la distance de 1 carrere
		ray->lineheight = (int)(ray->resolution_y / ray->walldistance);
		ray->drawstart = (-ray->lineheight / 2) + (ray->resolution_y / 2);
		ray->drawend = (ray->lineheight / 2) + (ray->resolution_y / 2);
		if (ray->drawstart < 0)
			ray->drawstart = 0;
		if (ray->drawend >= ray->resolution_y)
			ray->drawend = ray->resolution_y - 1;
		while(ray->drawstart < ray->drawend)
		{
			my_mlx_pixel_put(data, x, ray->drawstart, ray->color);
			ray->drawstart++;
		}
		x++;
	
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->display, 0, 0);
	return (0);
}
