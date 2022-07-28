/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:08:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_init_display(t_data *data)
{
	data->display = mlx_new_image(data->mlx, data->resolution_x,
			data->resolution_y);
	data->display_add = mlx_get_data_addr(data->display,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	return (0);
}

void	ft_init_key(t_key *key)
{
	key->move_forward = 0;
	key->move_back = 0;
	key->move_left = 0;
	key->move_right = 0;
	key->rotate_left = 0;
	key->rotate_right = 0;
}

void	ft_init_minimap(t_data *data, t_minimap *m, t_ray *ray)
{
	m->x = data->resolution_y / 25;
	m->y = data->resolution_y / 25;
	m->step = data->resolution_x / 100;
	m->height = 0;
	m->i = 0;
	m->j = 0;
	while (ray->map[m->height] != 0)
		m->height++;
	m->width = 0;
	while (ray->map[(int)ray->pos_y][m->width])
		m->width++;
	m->i = (int)ray->pos_x - 5;
	m->j = (int)ray->pos_y - 5;
	m->middle = (data->resolution_y / 25) + (5 * m->step) + (0.5 * m->step);
}
