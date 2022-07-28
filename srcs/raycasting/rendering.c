/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:31:47 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_put_ceiling_and_roof(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < data->resolution_y)
	{
		x = 0;
		if (y > data->resolution_y / 2)
			color = data->floor;
		else
			color = data->ceiling;
		while (x < data->resolution_x)
		{
			ft_my_mlx_pixel_put(data, x, y, color);
			x++;
		}
	y++;
	}
}

void	ft_init_ray(t_ray *ray, int x)
{
	ray->hit = 0;
	ray->text_select = 0;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->camera_x = 2 * x / ray->resolution_x - 1;
}

void	ft_movements(t_data *data)
{
	t_key	*key;

	key = &data->key;
	ft_move_straight(&data->ray_data, data, key);
	ft_move_right(&data->ray_data, data, key);
	ft_move_left(&data->ray_data, data, key);
	ft_rotate_left(&data->ray_data, data, key);
	ft_rotate_right(&data->ray_data, data, key);
	return ;
}

void	ft_wall_casting(t_data *data, t_ray *ray)
{
	int	x;

	x = 0;
	while (x < ray->resolution_x)
	{
		ft_init_ray(ray, x);
		ft_calc_ray_dir(ray);
		ft_calc_ray_delta(ray);
		ft_calc_rayside(ray);
		ft_launch_ray(ray);
		ft_calc_wall_distance(ray);
		ft_calc_wall_line(ray);
		ft_choose_texture(ray);
		ft_calc_x_texture(data);
		ft_calc_y_texture(data);
		ft_print_texture(data, ray, x);
		x++;
	}
}

int	ft_render_next_frame(t_data *data)
{
	t_ray	*ray;

	ray = &data->ray_data;
	ft_put_ceiling_and_roof(data);
	ft_movements(data);
	ft_wall_casting(data, ray);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->display, 0, 0);
	return (0);
}
