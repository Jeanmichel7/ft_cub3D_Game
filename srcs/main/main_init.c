/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:11:25 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/14 03:25:04 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	data->fov = 80;
	data->resolution_x = 930;
	data->resolution_y = 600;
}

void	ft_init_display(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->resolution_x, \
	data->resolution_y, "LE MEILLEUR JEU AU MONDE ");
	data->display = mlx_new_image(data->mlx, data->resolution_x, \
	data->resolution_y);
	data->display_add = mlx_get_data_addr(data->display, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
}
