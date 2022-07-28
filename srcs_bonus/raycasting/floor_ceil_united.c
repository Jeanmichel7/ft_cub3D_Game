/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil_united.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:44:02 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:00:18 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"
#if FOG == 1

void	ft_sub_ceiling_and_roof(t_data *data, int *color, int *shade, int ratio)
{
	if (y > data->resolution_y / 2)
	{
		*shade -= ratio;
		*color = ft_mix_color(data->floor, data->fog_color, *shade);
	}
	else
	{
		*shade += ratio;
		*color = ft_mix_color(data->ceiling, data->fog_color, *shade);
	}
}

void	ft_put_ceiling_and_roof(t_data *data)
{
	int		x;
	int		y;
	int		color;
	float	shade;
	float	ratio;

	ratio = 1 / ((float)data->resolution_y / 2);
	shade = 0.40;
	y = 0;
	while (y < data->resolution_y)
	{
		x = 0;
		while (x < data->resolution_x)
		{
			ft_my_mlx_pixel_put(data, x, y, color);
			x++;
		}
	y++;
	}
}
#else

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
#endif