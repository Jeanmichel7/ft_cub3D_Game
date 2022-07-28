/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:15:52 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/28 15:00:18 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"
#if FOG == 1

void	ft_draw_line_ceil(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int		width;
	int		*text2;
	float	shade;
	int		color;

	ray->text_select = TEXTURE_CEIL;
	text2 = data->texture[ray->text_select].addr;
	width = data->texture[ray->text_select].img_width;
	while (ray->drawend < ray->resolution_y)
	{
		color = width * flo->floortexty + flo->floortextx;
		if (color > width * data->texture[ray->text_select].img_height)
			color = width * data->texture[ray->text_select].img_height - 1;
		else if (color < 0)
			color = 0;
		shade = flo->distplayer * 0.50;
		ft_calc_pos_textfloor(ray, flo, data, width);
		ft_my_mlx_pixel_put(data, x, data->resolution_y - ray->drawend,
			ft_mix_color(text2[color], data->fog_color, shade));
		ray->drawend++;
	}
}

void	ft_draw_line_both(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int		width;
	int		*text1;
	int		*text2;
	float	shade;
	int		color;

	ray->text_select = TEXTURE_FLOOR;
	text1 = data->texture[ray->text_select].addr;
	text2 = data->texture[ray->text_select + 1].addr;
	width = data->texture[ray->text_select].img_width;
	while (ray->drawend < ray->resolution_y)
	{
		color = ft_check_color(width, data, flo, ray);
		ft_calc_pos_textfloor(ray, flo, data, width);
		shade = (data->resolution_y - ray->drawend)
			/ (float)(data->resolution_y) + 0.60;
		ft_my_mlx_pixel_put(data, x, ray->drawend,
			ft_mix_color(text1[color], data->fog_color, shade));
		ft_my_mlx_pixel_put(data, x, data->resolution_y - ray->drawend,
			ft_mix_color(text2[color], data->fog_color, shade));
		ray->drawend++;
	}
}

void	ft_draw_line_floor(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int		width;
	int		*text1;
	float	shade;
	int		color;

	ray->text_select = TEXTURE_FLOOR;
	text1 = data->texture[ray->text_select].addr;
	width = data->texture[ray->text_select].img_width;
	while (ray->drawend < ray->resolution_y)
	{
		color = width * flo->floortexty + flo->floortextx;
		if (color >= width * data->texture[ray->text_select].img_height)
			color = width * data->texture[ray->text_select].img_height - 1;
		else if (color < 0)
			color = 0;
		shade = (data->resolution_y - ray->drawend)
			/ (float)(data->resolution_y) + 0.60;
		ft_calc_pos_textfloor(ray, flo, data, width);
		ft_my_mlx_pixel_put(data, x, ray->drawend,
			ft_mix_color(text1[color], data->fog_color, shade));
		ray->drawend++;
	}
}
#else

void	ft_draw_line_ceil(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int	width;
	int	*text2;
	int	color;

	ray->text_select = TEXTURE_CEIL;
	text2 = data->texture[ray->text_select].addr;
	width = data->texture[ray->text_select].img_width;
	while (ray->drawend < ray->resolution_y)
	{
		color = width * flo->floortexty + flo->floortextx;
		if (color >= width * data->texture[ray->text_select].img_height)
			color = width * data->texture[ray->text_select].img_height - 1;
		if (color < 0)
			color = 0;
		ft_calc_pos_textfloor(ray, flo, data, width);
		ft_my_mlx_pixel_put(data, x, data->resolution_y - ray->drawend,
			text2[width * flo->floortexty + flo->floortextx]);
		ray->drawend++;
	}
}

void	ft_draw_line_both(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int	width;
	int	*text1;
	int	*text2;
	int	color;

	ray->text_select = TEXTURE_FLOOR;
	text1 = data->texture[ray->text_select].addr;
	text2 = data->texture[ray->text_select + 1].addr;
	width = data->texture[ray->text_select].img_width;
	while (ray->drawend < ray->resolution_y)
	{
		color = width * flo->floortexty + flo->floortextx;
		if (color >= width * data->texture[ray->text_select].img_height)
			color = width * data->texture[ray->text_select].img_height - 1;
		else if (color < 0)
			color = 0;
		ft_calc_pos_textfloor(ray, flo, data, width);
		ft_my_mlx_pixel_put(data, x, ray->drawend,
			text1[color]);
		ft_my_mlx_pixel_put(data, x, data->resolution_y - ray->drawend,
			text2[color]);
		ray->drawend++;
	}
}

#endif
