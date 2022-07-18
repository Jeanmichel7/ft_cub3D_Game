/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:34:26 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/19 00:39:18 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	manage_keys(int key, t_data *data)
{
	if (key == 65307 || key == 53)
		ft_exit_game(data);

	printf("key : %d\n", key);
	

	if (key == 'z')
	{
		data->ray_data.pos_x -= (cos(ft_conv_in_rad(data->ray_data.orientation)) * SPEED);
		data->ray_data.pos_y -= (sin(ft_conv_in_rad(data->ray_data.orientation)) * SPEED);
	}
	else if (key == 's')
	{
		data->ray_data.pos_x += (cos(ft_conv_in_rad(data->ray_data.orientation)) * SPEED);
		data->ray_data.pos_y += (sin(ft_conv_in_rad(data->ray_data.orientation)) * SPEED);
	}
	else if (key == 'd')
	{
		data->ray_data.orientation += 90;
		data->ray_data.pos_x -= (cos(ft_conv_in_rad(data->ray_data.orientation)) * SPEED);
		data->ray_data.pos_y -= (sin(ft_conv_in_rad(data->ray_data.orientation)) * SPEED);
		data->ray_data.orientation -= 90;
	}
	else if (key == 'q')
	{
		data->ray_data.orientation -= 90;
		data->ray_data.pos_x -= (cos(ft_conv_in_rad(data->ray_data.orientation)) * SPEED);
		data->ray_data.pos_y -= (sin(ft_conv_in_rad(data->ray_data.orientation)) * SPEED);
		data->ray_data.orientation += 90;
	}
	else if (key == 'a')
		data->ray_data.orientation += 10;
	else if (key == 'e')
		data->ray_data.orientation -= 10;


	ft_raycaster(data);


	return (0);
}
