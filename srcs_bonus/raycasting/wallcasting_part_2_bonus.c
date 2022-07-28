/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcasting_part_2_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:06:52 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_calc_wall_line(t_ray *ray)
{
	ray->lineheight = (int)(ray->resolution_y / ray->walldistance);
	ray->drawstart = (-ray->lineheight / 2) + (ray->resolution_y / 2);
	ray->drawend = (ray->lineheight / 2) + (ray->resolution_y / 2);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	if (ray->drawend >= ray->resolution_y)
		ray->drawend = ray->resolution_y - 1;
}

void	ft_calc_rayside(t_ray *ray)
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
}

void	ft_door_side_1(t_ray *ray)
{
	ray->wall_x -= floor(ray->wall_x);
	if (ray->wall_x < ray->size_door || ray->map_y != ray->pos_door_y
		|| ray->map_x != ray->pos_door_x)
	{
		ray->hit = 1;
		ray->text_select = TEXTURE_DOOR;
		ray->ray_touch_door = 1;
	}
	else
	{
		ray->ray_side_y -= (ray->ray_delta_y / 2);
		ray->door_before = 1;
	}
}

void	ft_door_side_2(t_ray *ray)
{
	ray->wall_x -= floor(ray->wall_x);
	if (ray->wall_x < ray->size_door || ray->map_y != ray->pos_door_y
		|| ray->map_x != ray->pos_door_x)
	{
		ray->hit = 1;
		ray->text_select = TEXTURE_DOOR;
		ray->ray_touch_door = 1;
	}
	else
	{
		ray->ray_side_x -= (ray->ray_delta_x / 2);
		ray->door_before = 1;
	}
}

void	ft_ray_touch_door(t_ray *ray)
{
	if (ray->side == 0)
	ray->ray_side_x += (ray->ray_delta_x / 2);
	else
		ray->ray_side_y += (ray->ray_delta_y / 2);
	if (ray->side == 0)
		ray->walldistance = (ray->ray_side_x - ray->ray_delta_x);
	else if (ray->side == 1)
		ray->walldistance = (ray->ray_side_y - ray->ray_delta_y);
	if (ray->side == 0)
		ray->wall_x = ray->pos_y + (ray->walldistance) * ray->raydir_y ;
	else
		ray->wall_x = ray->pos_x + (ray->walldistance) * ray->raydir_x;
	if (ray->side == 1 && (ray->wall_x >= ray->map_x)
		&& (ray->wall_x < ray->map_x + 1))
		ft_door_side_1(ray);
	else if (ray->side == 1)
			ray->text_select = TEXTURE_SIDE_DOOR;
	if (ray->side == 0 && (ray->wall_x >= ray->map_y)
		&& (ray->wall_x < ray->map_y + 1))
		ft_door_side_2(ray);
	else if (ray->side == 0)
			ray->text_select = TEXTURE_SIDE_DOOR;
}
