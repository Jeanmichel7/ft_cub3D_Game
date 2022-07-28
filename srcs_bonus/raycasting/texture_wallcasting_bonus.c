/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wallcasting_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:59:45 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
	if (ray->side == 0 && ray->raydir_x < 0)
		ray->text_select = 2;
}

void	ft_calc_x_texture(t_data *data)
{
	t_ray	*ray;
	double	old;

	ray = &data->ray_data;
	if (ray->side == 0)
		ray->wall_x = ray->pos_y + ray->walldistance * ray->raydir_y;
	else
		ray->wall_x = ray->pos_x + ray->walldistance * ray->raydir_x;
	if (ray->ray_touch_door == 1 && ray->map_x == ray->pos_door_x
		&& ray->map_y == ray->pos_door_y)
	{
		old = ray->wall_x - floor(ray->wall_x);
		ray->wall_x -= floor(ray->wall_x) - (1 - ray->size_door);
	}
	else
	ray->wall_x -= floor(ray->wall_x);
	ray->texx = (int)(ray->wall_x * data->texture[ray->text_select].img_width);
	if (ray->ray_touch_door == 1 && ray->map_x == ray->pos_door_x
		&& ray->map_y == ray->pos_door_y)
	ray->wall_x = old;
	if (ray->ray_touch_door == 1)
		ray->texx = data->texture[ray->text_select].img_width - ray->texx - 1;
	else if ((ray->side == 0 && ray->raydir_x > 0)
		|| (ray->side == 1 && ray->raydir_y < 0))
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

#if FOG == 1

void	ft_print_texture(t_data *data, t_ray *ray, int x)
{
	int		text_select;
	int		img_width;
	int		*img_add;
	int		color;
	float	shade;

	shade = data->zbuffer[x] * 0.50;
	text_select = ray->text_select;
	img_width = data->texture[text_select].img_width;
	img_add = data->texture[text_select].addr;
	while (ray->drawstart <= ray->drawend)
	{
		ray->texy = (int)ray->texpos
			& (data->texture[text_select].img_height - 1);
		ray->texpos += ray->step;
		color = ft_mix_color(img_add[img_width * ray->texy + ray->texx],
				data->fog_color, shade);
		ft_my_mlx_pixel_put(data, x, ray->drawstart, color);
		ray->drawstart++;
	}
}
#else

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
		ray->texy = (int)ray->texpos \
		& (data->texture[text_select].img_height - 1);
		ray->texpos += ray->step;
		ft_my_mlx_pixel_put(data, x, ray->drawstart,
			img_add[img_width * ray->texy + ray->texx]);
		ray->drawstart++;
	}
}
#endif