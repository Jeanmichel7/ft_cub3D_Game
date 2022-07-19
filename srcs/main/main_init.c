/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:11:25 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/19 15:04:48 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	ft_conv_in_rad(double degre)
{
	double	ret;

	ret = degre * PI / (double)180;
	return (ret);
}

void	ft_init_data(t_data *data)
{
	data->texture_N = NULL;
	data->texture_S = NULL;
	data->texture_W = NULL;
	data->texture_E = NULL;
	data->color_floor = -1;
	data->color_ceiling = -1;
	data->map.height = 0;
	data->map.width = 0;
	data->map.tab = NULL;
	data->is_map_started = 0;
	data->fd = -1;
	data->player_spawn_dir = 0;
	data->player_spawn_x = -1;
	data->player_spawn_y = -1;
	data->fov = 60;
	data->resolution_x = 960;
	data->resolution_y = 640;
	data->bpp = 32;
	data->size_line = data->resolution_x * 4;
	data->endian = 0;



	data->forward = 0;
	data->backward = 0;
	data->right = 0;
	data->left = 0;
	data->rotate_right = 0;
	data->rotate_left = 0;


	data->ray_data.orientation = -1;




}

void	ft_init_raycasing_data(t_data *d)
{
	d->ray_data.dist_cam_ecran = (d->resolution_x / 2) / tan(ft_conv_in_rad(d->fov / 2));
	d->ray_data.angle_between_radius = (float)d->fov / (float)d->resolution_x;
	d->ray_data.plan_x = d->resolution_x;
	d->ray_data.plan_y = d->resolution_y;
	d->ray_data.center_plan_x = d->ray_data.plan_x / 2;
	d->ray_data.center_plan_y = d->ray_data.plan_y / 2;
	d->ray_data.pos_x = d->player_spawn_x * BLOCK_SIZE + (BLOCK_SIZE / 2);
	d->ray_data.pos_y = d->player_spawn_y * BLOCK_SIZE + (BLOCK_SIZE / 2);
}

void	ft_init_display(t_data *data)
{
	ft_init_raycasing_data(data);

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->resolution_x, \
	data->resolution_y, "WOLFENCHTEIN");
	data->mlx_img = mlx_new_image(data->mlx, data->resolution_x, \
	data->resolution_y);
	data->img_data = mlx_get_data_addr(data->mlx_img, \
	&data->bpp, &data->size_line, &data->endian);

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
}
