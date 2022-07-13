/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:28:50 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/13 18:28:50 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_check_chang_dir(t_map_data *d)
{
	if (d->dir == 'E')
	{
		//check ca gauche (N)
		if (ft_move_is_valid(d->map[d->posY - 1][d->posX]))
			d->dir = 'N';
		else if (ft_move_is_valid(d->map[d->posY][d->posX + 1]))
			;
		else if (ft_move_is_valid(d->map[d->posY + 1][d->posX]))
			d->dir = 'S';
		else
			d->dir = 'W';
	}
	else if (d->dir == 'S')
	{
		//check ca gauche (E)
		if (ft_move_is_valid(d->map[d->posY][d->posX + 1]))
			d->dir = 'E';
		else if (ft_move_is_valid(d->map[d->posY + 1][d->posX]))
			;
		else if (ft_move_is_valid(d->map[d->posY][d->posX - 1]))
			d->dir = 'W';
		else
			d->dir = 'N';
	}
	else if (d->dir == 'W')
	{
		//check ca gauche (S)
		if (ft_move_is_valid(d->map[d->posY + 1][d->posX]))
			d->dir = 'S';
		else if (ft_move_is_valid(d->map[d->posY][d->posX - 1]))
			;
		else if (ft_move_is_valid(d->map[d->posY - 1][d->posX]))
			d->dir = 'N';
		else
			d->dir = 'E';
	}
	else if (d->dir == 'N')
	{
		//check ca gauche (W)
		if (ft_move_is_valid(d->map[d->posY][d->posX - 1]))
			d->dir = 'W';
		else if (ft_move_is_valid(d->map[d->posY - 1][d->posX]))
			;
		else if (ft_move_is_valid(d->map[d->posY][d->posX + 1]))
			d->dir = 'E';
		else
			d->dir = 'S';
	}
	ft_move(d);
}


int	ft_follow_wall(t_map_data *d)
{
	int	i;

	printf("position (%d, %d)\n", d->posX, d->posY);
	i = 0;
	while (i == 0 || d->nb_pass != 3)
	{
		printf("position avnt(%d, %d) -> %c\n", d->posX, d->posY, d->dir);
		if (d->dir == 'E')
		{
			if (ft_check_out(d))
				return (1);
		}
		else if (d->dir == 'S')
		{
			if (ft_check_out(d))
				return (1);
		}
		else if (d->dir == 'W')
		{
			if (ft_check_out(d))
				return (1);
		}
		else if (d->dir == 'N')
		{
			if (ft_check_out(d))
				return (1);
		}
		ft_check_chang_dir(d);
		if (d->posX == d->x_start && d->posY == d->y_start)
			d->nb_pass += 1;
		printf("position apres(%d, %d) -> %c\n", d->posX, d->posY, d->dir);
		printf("nb_pass %d\n", d->nb_pass);
		ft_print_map(d);
		i++;
	}
	return (0);
}


/*
int	ft_follow_wall(t_map_data *d)
{
	int	i;

	printf("position (%d, %d)\n", d->posX, d->posY);
	i = 0;
	while (i == 0 || d->nb_pass != 3)
	{
		printf("position avnt(%d, %d) -> %c\n", d->posX, d->posY, d->dir);
		if (d->dir == 'E' && ft_check_out(d))
			return (1);
		else if (d->dir == 'S' && ft_check_out(d))
			return (1);
		else if (d->dir == 'W' && ft_check_out(d))
			return (1);
		else if (d->dir == 'N' && ft_check_out(d))
			return (1);
		ft_check_chang_dir(d);
		if (d->posX == d->x_start && d->posY == d->y_start)
			d->nb_pass += 1;
		printf("position apres(%d, %d) -> %c\n", d->posX, d->posY, d->dir);
		printf("nb_pass %d\n", d->nb_pass);
		ft_print_map(d);
		i++;
	}
	return (0);
}

*/