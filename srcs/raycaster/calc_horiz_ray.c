/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_horiz_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 23:47:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/18 23:56:13 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_block_is_wall_on_horiz_next_y(t_data *d, double x, double y, int sens)
{
	int	i_x;
	int	i_y;

	//printf("pos teste (%f, %f)\n", x, y);

	i_x = x / 48;
	if (sens == 1)
		i_y = y / 48 - sens;
	else
		i_y = y / 48;

	//printf("ind teste tab[%d][%d]\n", i_y, i_x);
	
	if (d->map.tab[i_y][i_x] == '1')
	{
		//printf("touche le mur en tab[%d][%d]\n",i_y, i_x);
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
			return (sqrt(pow((y_test - d->ray_data.pos_y), 2) + pow((d->ray_data.pos_x - x_test), 2)));
		else
			return (sqrt(pow((y_test - d->ray_data.pos_y), 2) + pow((x_test - d->ray_data.pos_x), 2)));
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
	int		j;
	//int		sens_vert;

	int		posY_block;

	//printf("pos x : %f, pos y : %f\n", d->ray_data.pos_x, d->ray_data.pos_y);

	posY_block = (int)d->ray_data.pos_y % BLOCK_SIZE;
	//printf("pos y block : %d\n", posY_block);


	//	
	//if ((angle > 0 && angle <= 90) || (angle > 270 && angle <= 360))
	//	sens_vert = 1;
	//else
	//	sens_vert = -1;

	if (angle > 0 && angle <= 180)
		sens_horiz = 1;
	else
		sens_horiz = -1;



	if (sens_horiz == 1)
	{
		x0 = (posY_block) / (tan(ft_conv_in_rad(angle)));
		x1 = (posY_block + BLOCK_SIZE) / tan(ft_conv_in_rad(angle));
	}
	else
	{
		x0 = (BLOCK_SIZE - posY_block) / (tan(ft_conv_in_rad(angle)));
		x1 = (BLOCK_SIZE - posY_block + BLOCK_SIZE) / tan(ft_conv_in_rad(angle));
	}
	x = x1 - x0;



	//pos x block ok si on regarde vers le haut
	
	//printf("x : %f, x0 : %f, x1 : %f\n", x, x0, x1);
	
	
	
	if (sens_horiz == 1)
	{
		x_test = d->ray_data.pos_x + (sens_horiz * x0);
		y_test = d->ray_data.pos_y - (sens_horiz * (posY_block));
	}
	else
	{
		x_test = d->ray_data.pos_x + (sens_horiz * x0);
		y_test = d->ray_data.pos_y - (sens_horiz * (BLOCK_SIZE - posY_block));
	}
	//printf("pos x0 (%f, %f)\n", x_test, y_test);

	if (x_test < (double)0 || y_test < (double)0 || x_test > d->map.width * 48 || y_test > d->map.height * 48)
	{
		//printf("Touche aucun mur\n");
		return (-1);
	}
	
	j = 1;
	while (ft_block_is_wall_on_horiz_next_y(d, x_test, y_test, sens_horiz) != 1)	// def distance max ?
	{

		if (angle > 0 && angle <= 180)
			sens_horiz = 1;
		else
			sens_horiz = -1;

		if (sens_horiz == 1)
		{
			x_test = d->ray_data.pos_x + (sens_horiz * (x0 + (j * x)));
			y_test = d->ray_data.pos_y - (sens_horiz * (posY_block + (j * BLOCK_SIZE)));
		}
		else
		{
			x_test = d->ray_data.pos_x + (sens_horiz * (x0 + (j * x)));
			y_test = d->ray_data.pos_y - (sens_horiz * (BLOCK_SIZE - posY_block + (j * BLOCK_SIZE)));
		}



		if (x_test < (double)0 || y_test < (double)0 || x_test > d->map.width * 48 || y_test > d->map.height * 48)
		{
			//printf("Touche aucun mur\n");
			return (-1);
		}
		j++;
	}

	return (ft_calcul_dist_horiz(angle, d, x_test, y_test));
}
