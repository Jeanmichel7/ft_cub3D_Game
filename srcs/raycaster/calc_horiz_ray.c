/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_horiz_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:47:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/18 02:59:50 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_block_is_wall_on_horiz_next_y(t_data *d, double x, double y, int sens)
{
	int	i_x;
	int	i_y;

	i_x = x / 48;
	if (sens)
		i_y = y / 48 - sens;
	else
		i_y = y / 48;
	if (d->map.tab[i_y][i_x] == '1')
	{
		printf("touche le mur en tab[%d][%d]\n",i_y, i_x);
		return (1);
	}
	else
		return (0);
}

double	ft_calcul_dist_horiz(double angle, t_data *d, double x_test, double y_test)
{
	if (angle > 0 && angle <= 180)
	{
		if (angle > 0 && angle <= 90)
			return (sqrt(pow((d->ray_data.pos_y - y_test), 2) + pow((x_test - d->ray_data.pos_x), 2)));
		else if (angle > 90 && angle <= 180)
			return (sqrt(pow((d->ray_data.pos_y - y_test), 2) + pow((d->ray_data.pos_x - x_test), 2)));
	}
	else
	{
		if (angle > 180 && angle <= 270)
			return (sqrt( pow((y_test - d->ray_data.pos_y), 2) + pow((d->ray_data.pos_x - x_test), 2)));
		else
			return (sqrt( pow((y_test - d->ray_data.pos_y), 2) + pow((x_test - d->ray_data.pos_x), 2)));
	}
	return (0);
}

double	ft_dist_sur_x(t_data *d, double angle)
{
	double	x0;
	double	x1;
	double	x;
	double	x_test;
	double	y_test;
	int		sens_horiz;
	//int		sens_vert;

	int		j;

	if (angle > 0 && angle <= 180)
		sens_horiz = 1;
	else
		sens_horiz = -1;
		
	//if ((angle > 0 && angle <= 90) || (angle > 270 && angle <= 360))
	//	sens_vert = 1;
	//else
	//	sens_vert = -1;

	// angle % 90 ?!
	x0 = (BLOCK_SIZE / 2) / (tan(ft_conv_in_rad(angle))); // BLOCK / 2 -> position réel dans le bloc sur y
	x1 = ((BLOCK_SIZE / 2) + BLOCK_SIZE) / tan(ft_conv_in_rad(angle));
	x = x1 - x0;
	//printf("x : %f, x0 : %f, x1 : %f\n", x, x0, x1);

	x_test = d->ray_data.pos_x + (sens_horiz * x0);
	y_test = d->ray_data.pos_y - (sens_horiz * (BLOCK_SIZE / 2));
	printf("pos x0 (%f, %f)\n", x_test, y_test);

	j = 1;
	while (ft_block_is_wall_on_horiz_next_y(d, x_test, y_test, sens_horiz) != 1)	// def distance max ?
	{
		x_test = d->ray_data.pos_x + (sens_horiz * (x0 + (j * x)));
		y_test = d->ray_data.pos_y - (sens_horiz * ((BLOCK_SIZE / 2) + (j * BLOCK_SIZE)));
		j++;
	}

	return (ft_calcul_dist_horiz(angle, d, x_test, y_test));
}
