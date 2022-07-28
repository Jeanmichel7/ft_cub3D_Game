/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:38:32 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

typedef struct floor_casting
{
	double	floorxwall;
	double	floorywall;
	double	distwall;
	double	distplayer;
	double	currentdist;
	double	weight;
	double	currentfloorx;
	double	currentfloory;
	int		floortextx;
	int		floortexty;
}		t_flo;

void	ft_wall_direction(t_ray *ray, t_flo *flo)
{
	if (ray->side == 0 && ray->raydir_x > 0)
	{
		flo->floorxwall = ray->map_x;
		flo->floorywall = ray->map_y + ray->wall_x;
	}
	else if (ray->side == 0 && ray->raydir_x < 0)
	{
		flo->floorxwall = ray->map_x + 1;
		flo->floorywall = ray->map_y + ray->wall_x;
	}
	else if (ray->side == 1 && ray->raydir_y > 0)
	{
		flo->floorxwall = ray->map_x + ray->wall_x;
		flo->floorywall = ray->map_y;
	}
	else
	{
		flo->floorxwall = ray->map_x + ray->wall_x;
		flo->floorywall = ray->map_y + 1;
	}
}

void	ft_calc_pos_textfloor(t_ray *ray, t_flo *flo, t_data *data, int width)
{
	flo->currentdist = ray->resolution_y
		/ (2 * ray->drawend - ray->resolution_y);
	flo->weight = (flo->currentdist - flo->distplayer)
		/ (flo->distwall - flo->distplayer);
	flo->currentfloorx = flo->weight * flo->floorxwall
		+ (1 - flo->weight) * ray->pos_x;
	flo->currentfloory = flo->weight * flo->floorywall
		+ (1 - flo->weight) * ray->pos_y;
	flo->floortextx = (int)(flo->currentfloorx * width)
		% width;
	flo->floortexty = (int)(flo->currentfloory * width)
		% data->texture[ray->text_select].img_height;
}

void	ft_draw_line(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int	width;
	int	*text1;

	ray->text_select = 5;
	text1 = data->texture[ray->text_select].addr;
	width = data->texture[ray->text_select].img_width;
	while (ray->drawend < ray->resolution_y + 1)
	{
		ft_calc_pos_textfloor(ray, flo, data, width);
		ft_my_mlx_pixel_put(data, x, ray->drawend,
			text1[width * flo->floortexty + flo->floortextx]);
		ray->drawend++;
	}
}

void	ft_floor_casting(t_data *data, t_ray *ray, int x)
{
	t_flo	flo;

	ray->drawend = ray->drawend;
	flo.distwall = ray->walldistance;
	flo.distplayer = 0;
	ft_wall_direction(ray, &flo);
	if (ray->drawend < 0)
		ray->drawend = ray->resolution_y;
	ft_draw_line(data, ray, &flo, x);
}
