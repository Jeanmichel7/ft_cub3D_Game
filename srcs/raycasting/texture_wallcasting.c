/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wallcasting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:59:45 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_choose_texture(t_ray *ray)
{
	if (ray->text_select != 0)
		return ;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->text_select = 0;
	if (ray->side == 1 && ray->raydir_y > 0)
		ray->text_select = 1;
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->text_select = 3;
	if (ray->side == 0 && ray->raydir_x < 0)
		ray->text_select = 2;
}

void	ft_calc_x_texture(t_data *data)
{
	t_ray	*ray;

	ray = &data->ray_data;
	if (ray->side == 0)
		ray->wall_x = ray->pos_y + ray->walldistance * ray->raydir_y;
	else
		ray->wall_x = ray->pos_x + ray->walldistance * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->texx = (int)(ray->wall_x * data->texture[ray->text_select].img_width);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->texx = data->texture[ray->text_select].img_width - ray->texx - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->texx = data->texture[ray->text_select].img_width - ray->texx - 1;
}

void	ft_calc_y_texture(t_data *data)
{
	t_ray	*ray;

	ray = &data->ray_data;
	ray->step = 1 * (double)data->texture[ray->text_select].img_height
		/ (double)ray->lineheight;
	ray->texpos = (ray->drawstart - ray->resolution_y
			/ 2 + ray->lineheight / 2) * ray->step;
}

void	ft_print_texture(t_data *data, t_ray *ray, int x)
{
	int	text_select;
	int	img_width;
	int	*img_add;

	text_select = ray->text_select;
	img_width = data->texture[text_select].img_width;
	img_add = data->texture[text_select].addr;
	while (ray->drawstart <= ray->drawend)
	{
		ray->texy = (int)ray->texpos & \
		(data->texture[text_select].img_height - 1);
		ray->texpos += ray->step;
		ft_my_mlx_pixel_put(data, x, ray->drawstart,
			img_add[img_width * ray->texy + ray->texx]);
		ray->drawstart++;
	}
}
