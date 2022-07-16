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

void	ft_sub_checker_chang_dir_e(t_map_data *d)
{
	if (ft_move_is_valid(d, d->map[d->posY - 1][d->posX]))
		d->dir = 'N';
	else if (ft_move_is_valid(d, d->map[d->posY][d->posX + 1]))
		;
	else if (ft_move_is_valid(d, d->map[d->posY + 1][d->posX]))
		d->dir = 'S';
	else
		d->dir = 'W';
}

void	ft_sub_checker_chang_dir_s(t_map_data *d)
{
	if (ft_move_is_valid(d, d->map[d->posY][d->posX + 1]))
		d->dir = 'E';
	else if (ft_move_is_valid(d, d->map[d->posY + 1][d->posX]))
		;
	else if (ft_move_is_valid(d, d->map[d->posY][d->posX - 1]))
		d->dir = 'W';
	else
		d->dir = 'N';
}

void	ft_sub_checker_chang_dir_w(t_map_data *d)
{
	if (ft_move_is_valid(d, d->map[d->posY + 1][d->posX]))
		d->dir = 'S';
	else if (ft_move_is_valid(d, d->map[d->posY][d->posX - 1]))
		;
	else if (ft_move_is_valid(d, d->map[d->posY - 1][d->posX]))
		d->dir = 'N';
	else
		d->dir = 'E';
}

void	ft_sub_checker_chang_dir_n(t_map_data *d)
{
	if (ft_move_is_valid(d, d->map[d->posY][d->posX - 1]))
		d->dir = 'W';
	else if (ft_move_is_valid(d, d->map[d->posY - 1][d->posX]))
		;
	else if (ft_move_is_valid(d, d->map[d->posY][d->posX + 1]))
		d->dir = 'E';
	else
		d->dir = 'S';
}

int	ft_follow_wall(t_map_data *d)
{
	int	i;

	i = 0;
	while (i == 0 || d->nb_pass != 3)
	{
		if (d->dir == 'E' || d->dir == 'S' || d->dir == 'W' || d->dir == 'N')
		{
			if (ft_check_out(d))
				return (1);
		}
		if (d->dir == 'E')
			ft_sub_checker_chang_dir_e(d);
		else if (d->dir == 'S')
			ft_sub_checker_chang_dir_s(d);
		else if (d->dir == 'W')
			ft_sub_checker_chang_dir_w(d);
		else if (d->dir == 'N')
			ft_sub_checker_chang_dir_n(d);
		ft_move(d);
		if (d->posX == d->x_start && d->posY == d->y_start)
			d->nb_pass += 1;
		//ft_print_map(d);
		i++;
	}
	return (0);
}
