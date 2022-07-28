/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_keyboard_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:12:02 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_move_straight(t_ray *ray, t_data *data, t_key *key)
{
	if (key->move_back == 1)
	{
		if (ray->map[(int)(ray->pos_y - ray->dir_y * data->move_speed)]
			[(int)(ray->pos_x)] <= '0')
			ray->pos_y -= ray->dir_y * data->move_speed;
		if (ray->map[(int)(ray->pos_y)]
			[(int)(ray->pos_x - ray->dir_x * data->move_speed)] <= '0')
			ray->pos_x -= ray->dir_x * data->move_speed;
	}
	if (key->move_forward == 1)
	{
		if (ray->map[(int)(ray->pos_y)]
			[(int)(ray->pos_x + ray->dir_x * data->move_speed)] <= '0')
			ray->pos_x += ray->dir_x * data->move_speed;
		if (ray->map[(int)(ray->pos_y + ray->dir_y * data->move_speed)]
			[(int)(ray->pos_x)] <= '0')
			ray->pos_y += ray->dir_y * data->move_speed;
	}
}

void	ft_move_right(t_ray *ray, t_data *data, t_key *key)
{
	double	alpha;

	if (key->move_right == 1)
	{
		if (ray->dir_y > 0)
			alpha = acos(ft_check_double_overflow(ray->dir_x));
		else
			alpha = -acos(ft_check_double_overflow(ray->dir_x));
		if (ray->map[(int)((sin(alpha + M_PI / 2) * data->move_speed)
				+ ray->pos_y)][(int)(ray->pos_x)] <= '0')
			ray->pos_y = (sin(alpha + M_PI / 2) * data->move_speed)
				+ ray->pos_y;
		if (ray->map[(int)(ray->pos_y)][(int)((cos(alpha + M_PI / 2)
			* data->move_speed) + ray->pos_x)] <= '0')
			ray->pos_x = (cos(alpha + M_PI / 2) * data->move_speed)
				+ ray->pos_x;
	}
}

void	ft_move_left(t_ray *ray, t_data *data, t_key *key)
{
	double	alpha;

	if (key->move_left == 1)
	{
		if (ray->dir_y > 0)
			alpha = acos(ft_check_double_overflow(ray->dir_x));
		else
			alpha = -acos(ft_check_double_overflow(ray->dir_x));
		if (ray->map[(int)((-sin(alpha + M_PI / 2) * data->move_speed)
				+ray->pos_y)][(int)(ray->pos_x)] <= '0')
			ray->pos_y = (-sin(alpha + M_PI / 2) * data->move_speed)
				+ ray->pos_y;
		if (ray->map[(int)(ray->pos_y)][(int)((-cos(alpha + M_PI / 2)
			* data->move_speed) + ray->pos_x)] <= '0')
			ray->pos_x = (-cos(alpha + M_PI / 2) * data->move_speed)
				+ ray->pos_x;
	}
}

void	ft_rotate_right(t_ray *ray, t_data *data, t_key *key)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir_x;
	old_plane_x = ray->plane_x;
	if (key->rotate_right == 1)
	{
		old_dir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(data->rotate_speed)
			- ray->dir_y * sin(data->rotate_speed);
		ray->dir_y = old_dir_x * sin(data->rotate_speed)
			+ ray->dir_y * cos(data->rotate_speed);
		old_plane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(data->rotate_speed)
			- ray->plane_y * sin(data->rotate_speed);
		ray->plane_y = old_plane_x * sin(data->rotate_speed)
			+ ray->plane_y * cos(data->rotate_speed);
	}
}

void	ft_rotate_left(t_ray *ray, t_data *data, t_key *key)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = ray->dir_x;
	old_plane_x = ray->plane_x;
	if (key->rotate_left == 1)
	{
		old_dir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(-data->rotate_speed)
			- ray->dir_y * sin(-data->rotate_speed);
		ray->dir_y = old_dir_x * sin(-data->rotate_speed)
			+ ray->dir_y * cos(-data->rotate_speed);
		old_plane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(-data->rotate_speed)
			- ray->plane_y * sin(-data->rotate_speed);
		ray->plane_y = old_plane_x * sin(-data->rotate_speed)
			+ ray->plane_y * cos(-data->rotate_speed);
	}
}
