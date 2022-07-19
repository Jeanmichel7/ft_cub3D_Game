/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:48:35 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/19 11:47:49 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

// X position * 4 + Line size * Y position * 4
void	ft_fill_line(t_data *d)
{
	long 	pos;
	int		i;

	i = 0;
	while (i < (d->resolution_x))
	{
		pos = i * 4 + ((d->size_line) * d->player_spawn_y);
		d->img_data[pos] = (char)255;
		d->img_data[pos + 1] = (char)255;
		d->img_data[pos + 2] = (char)255;
		i++;
	}
	//mlx_destroy_image()
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->mlx_img, 0, 0);

}
