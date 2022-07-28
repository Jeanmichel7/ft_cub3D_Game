/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:08:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/21 02:53:19 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
