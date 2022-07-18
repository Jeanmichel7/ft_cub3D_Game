/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:34:26 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/18 23:37:02 by jrasser          ###   ########.fr       */
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
		data->ray_data.pos_y -= SPEED;
	}

	if (key == 's')
		data->ray_data.pos_y += SPEED;
	if (key == 'd')
		data->ray_data.pos_x += SPEED;
	if (key == 'q')
		data->ray_data.pos_x -= SPEED;


	ft_raycaster(data);


	return (0);
}
