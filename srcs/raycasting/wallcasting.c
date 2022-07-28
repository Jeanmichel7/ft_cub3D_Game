/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:02:24 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_calc_ray_dir(t_ray *ray)
{
	ray->raydir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->raydir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	if (ray->raydir_x == 0)
		ray->raydir_x = 0.000001;
	if (ray->raydir_y == 0)
		ray->raydir_y = 0.000001;
}

void	ft_calc_ray_delta(t_ray *ray)
{
		ray->ray_delta_y = fabs(1 / ray->raydir_y);
		ray->ray_delta_x = fabs(1 / ray->raydir_x);
}

void	ft_calc_rayside(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->ray_side_x = (ray->pos_x - ray->map_x) * ray->ray_delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->ray_side_x = (ray->map_x + 1 - ray->pos_x) * ray->ray_delta_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->ray_side_y = (ray->pos_y - ray->map_y) * ray->ray_delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->ray_side_y = (ray->map_y + 1 - ray->pos_y) * ray->ray_delta_y;
	}
}

void	ft_launch_ray(t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->ray_side_x < ray->ray_side_y)
		{
			ray->ray_side_x += ray->ray_delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->ray_side_y += ray->ray_delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map[ray->map_y][ray->map_x] == '1'
			|| ray->map[ray->map_y][ray->map_x] == '2')
			ray->hit = 1;
		if (ray->map[ray->map_y][ray->map_x] == '2')
			ray->text_select = 4;
	}
}

void	ft_calc_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->walldistance = (ray->ray_side_x - ray->ray_delta_x);
	else if (ray->side == 1)
		ray->walldistance = (ray->ray_side_y - ray->ray_delta_y);
}
