/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:33:46 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/19 01:13:23 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void	ft_fill_column(t_data *d, int j, double height)
{
	long	pos;
	int		i;
	int		begin_wall;
	int		end_wall;

	begin_wall = (d->resolution_y - height) / 2;
	end_wall = begin_wall + height;

	i = 0;
	while (i < d->resolution_y)
	{
		pos = j * 4 + ((d->size_line) * i);

		if (i < begin_wall)
		{
			d->img_data[pos] = 100;
			d->img_data[pos + 1] = 100;
			d->img_data[pos + 2] = 100;
		}
		else if (i > begin_wall && i < end_wall)
		{
			d->img_data[pos] = 255;
			d->img_data[pos + 1] = 255;
			d->img_data[pos + 2] = 255;
		}
		else
		{
			d->img_data[pos] = 100;
			d->img_data[pos + 1] = 100;
			d->img_data[pos + 2] = 100;
		}

		/*
		if (i < begin_wall)
			d->img_data[pos] = (char)d->color_ceiling;
		else if (i >= begin_wall && i <= end_wall)
			d->img_data[pos] = (char)16777215;
		else
			d->img_data[pos] = (char)d->color_floor;
		*/
		i++;
	}

	//mlx_destroy_image()
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->mlx_img, 0, 0);
}


double	ft_correct_fish_eye(double dist, double angle)
{
	double	ret;

	ret = dist;
	if ((angle > 0 && angle < 45))
		ret = dist * cos(ft_conv_in_rad(angle));
	else if ((angle > 45 && angle < 90))
		ret = dist * cos(ft_conv_in_rad(90 - angle));
	else if (angle > 90 && angle <= 135)
		ret = dist * cos(ft_conv_in_rad(angle - 90));
	else if (angle > 135 && angle <= 180)
		ret = dist * cos(ft_conv_in_rad(180 - angle));
	else if (angle > 180 && angle <= 225)
		ret = dist * cos(ft_conv_in_rad(angle - 180));
	else if (angle > 225 && angle <= 270)
		ret = dist * cos(ft_conv_in_rad(270 - angle));
	else if (angle > 270 && angle <= 315)
		ret = dist * cos(ft_conv_in_rad(angle - 270));
	else if (angle > 315 && angle <= 360)
		ret = dist * cos(ft_conv_in_rad(360 - angle));
	return (ret);
}

double	ft_new_angle(t_data *d, double angle)
{
	double ret;

	if (angle - d->ray_data.angle_between_radius < (double)0)
		ret = 360 - angle;
	else
		ret = angle - d->ray_data.angle_between_radius;
	return (ret);
}

void	ft_raycaster(t_data *d)
{
	int		i;
	double	angle;

	double	dist_sur_x = -1;
	double	dist_sur_y = -1;
	double	dist;

	double	display_height;
	double	dist_correct;


	i = 0;
	angle = d->ray_data.orientation + (d->fov / 2);

	// Point de dépar
	//printf("pt de depart (%f, %f)\n", d->ray_data.pos_x, d->ray_data.pos_y);
	//int i_spawn_x = d->ray_data.pos_x / 48;	// int -> tronc
	//int i_spawn_y = d->ray_data.pos_y / 48;	// int -> tronc
	//printf("spawner[%d][%d] = %c\n\n\n", i_spawn_y, i_spawn_x, d->map.tab[i_spawn_y][i_spawn_x]);

	while (i < d->resolution_x)
	{
		//printf("angle %f, i : %d\n", angle, i);

		dist_sur_x = ft_dist_sur_x(d, angle);
		//printf("distance sur horizontale : %f\n\n\n", dist_sur_x);

		dist_sur_y = ft_dist_sur_y(d, angle);
		//printf("distance sur vertical : %f\n\n\n", dist_sur_y);

		if (dist_sur_y == -1) // les 2 a -1
			dist = dist_sur_x;
		else if (dist_sur_x == -1)
			dist = dist_sur_y;
		else if (dist_sur_x <= dist_sur_y)
			dist = dist_sur_x;
		else if (dist_sur_y < dist_sur_x)
			dist = dist_sur_y;
		//printf("distance du rayon : %f\n\n", dist);

		dist_correct = ft_correct_fish_eye(dist, angle);
		//dist_correct = dist;
		display_height = (d->ray_data.dist_cam_ecran * BLOCK_SIZE) / (dist_correct);
		ft_fill_column(d, i, display_height);

		angle = ft_new_angle(d, angle);
		i++;
	}
}


