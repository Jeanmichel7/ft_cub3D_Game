/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vert_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:59:54 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/18 20:10:01 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_block_is_wall_on_vert_next_x(t_data *d, double x, double y, int sens)
{
	int	i_x;
	int	i_y;

	//printf("pos teste (%f, %f)\n", x, y);

	if (sens == 1)
		i_x = x / 48;
	else
		i_x = (x / 48) - 1;
	i_y = y / 48;
	//printf("ind teste tab[%d][%d]\n", i_y, i_x);

	if (i_y >= 0 && d->map.tab[i_y][i_x] == '1')
	{
		//printf("touche le mur en tab[%d][%d]\n\n", i_y, i_x);
		return (1);
	}
	else
		return (0);
}

double	ft_calcul_dist_vert(double angle, t_data *d, double x_test, double y_test)
{
	if (angle > 0 && angle <= 180)
	{
		if (angle > 0 && angle <= 90)
			return (sqrt(pow((d->ray_data.pos_y - y_test), 2) + pow((x_test - d->ray_data.pos_x), 2)));
		else if (angle > (double)90 && angle <= (double)180)
			return (sqrt(pow((d->ray_data.pos_y - y_test), 2) + pow((d->ray_data.pos_x - x_test), 2)));
	}
	else
	{
		if (angle > (double)180 && angle <= (double)270)
			return (sqrt(pow((y_test - d->ray_data.pos_y), 2) + pow((d->ray_data.pos_x - x_test), 2)));
		else
			return (sqrt(pow((y_test - d->ray_data.pos_y), 2) + pow((x_test - d->ray_data.pos_x), 2)));
	}
	return (0);
}

double	ft_dist_sur_y(t_data *d, double angle)
{
	double	y0;
	double	y1;
	double	y;
	double	x_test;
	double	y_test;
	//int		sens_horiz;
	int		sens_vert;
	int		j;

	//if (angle > 0 && angle <= 180)
	//	sens_horiz = 1;
	//else
	//	sens_horiz = -1;


	y0 = (BLOCK_SIZE / 2) * (tan(ft_conv_in_rad(angle)));	// BLOCK / 2 -> position réel dans le bloc sur x
	y1 = ((BLOCK_SIZE / 2) + BLOCK_SIZE) * tan(ft_conv_in_rad(angle));
	y = y1 - y0;
	//printf("y : %f, y0 : %f, y1 : %f\n", y, y0, y1);

	if ((angle > 0 && angle <= 90) || (angle > 270 && angle <= 360))
		sens_vert = 1;
	else
		sens_vert = -1;
	//if (angle > 0 && angle <= 180)
	//	sens_horiz = 1;
	//else
	//	sens_horiz = -1;

	x_test = d->ray_data.pos_x + (sens_vert * (BLOCK_SIZE / 2));
	y_test = d->ray_data.pos_y - (sens_vert * y0);
	//printf("pos y0 (%f, %f)\n", x_test, y_test);


	if (x_test < (double)0 || y_test < (double)0 || x_test > d->map.width * 48 || y_test > d->map.height * 48)
	{
		//printf("Touche aucun mur\n");
		return (-1);
	}


	j = 1;
	//while (x_test && y_test && x_test < d->map.width * 48 && y < d->map.height * 48
	//&& ft_block_is_wall_on_vert_next_x(d, x_test, y_test, sens_vert) != 1)	// def distance max ?
	while (ft_block_is_wall_on_vert_next_x(d, x_test, y_test, sens_vert) != 1)
	{

		//if (angle > 0 && angle <= 180)
		//	sens_horiz = 1;
		//else
		//	sens_horiz = -1;
			
		if ((angle > 0 && angle <= 90) || (angle > 270 && angle <= 360))
			sens_vert = 1;
		else
			sens_vert = -1;

		x_test = d->ray_data.pos_x + (sens_vert * ((BLOCK_SIZE / 2) + (j * BLOCK_SIZE)));
		y_test = d->ray_data.pos_y - ((sens_vert) * (y0 + (j * y)));
		//printf("pos y- (sens hori* y0 + j* y)\n");
		//printf("%f - (%d * %f + %d * %f)\n", 
		//d->ray_data.pos_y,
		//sens_horiz,
		//y0, j, y);
		if (x_test < (double)0 || y_test < (double)0 || x_test > d->map.width * 48 || y_test > d->map.height * 48) // distance max ?
		{
			//printf("Touche aucun mur\n");
			return (-1);
		}
		
		j++;
	}
	return (ft_calcul_dist_vert(angle, d, x_test, y_test));
}
