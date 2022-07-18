/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:33:46 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/18 15:24:12 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"




void	ft_raycaster(t_data *d)
{
	int		i;
	double	angle;

	double	dist_sur_x;
	double	dist_sur_y;
	double	dist;



	i = 0;
	angle = d->ray_data.orientation + (d->fov / 2);

	// Point de dépar
	printf("pt de depart (%f, %f)\n", d->ray_data.pos_x, d->ray_data.pos_y);
	int i_spawn_x = d->ray_data.pos_x / 48;	// int -> tronc
	int i_spawn_y = d->ray_data.pos_y / 48;	// int -> tronc
	printf("spawner[%d][%d] = %c\n\n\n", i_spawn_y, i_spawn_x, d->map.tab[i_spawn_y][i_spawn_x]);


	while (i < d->resolution_x)
	{
		printf("angle %f, i : %d\n", angle, i);

		//DISTANCE SUR X
		dist_sur_x = ft_dist_sur_x(d, angle);
		//printf("distance sur horizontale : %f\n\n\n", dist_sur_x);


		//DIST sur Y
		dist_sur_y = ft_dist_sur_y(d, angle);
		//printf("distance sur vertical : %f\n\n\n", dist_sur_y);


		if (dist_sur_y == -1)
			dist = dist_sur_x;
		else if (dist_sur_x == -1)
			dist = dist_sur_y;
		else if (dist_sur_x <= dist_sur_y)
			dist = dist_sur_x;
		else if (dist_sur_y < dist_sur_x)
			dist = dist_sur_y;
		else
			printf("calcul distance final etrange\n");

		printf("dist_sur_x : %f\ndist_sur_y: %f\n", dist_sur_x, dist_sur_y);
		printf("distance du rayon : %f\n\n", dist);


		angle -= d->ray_data.angle_between_radius;
		i++;
	}
}


