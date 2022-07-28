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

void	ft_sub_checker_chang_dir_l_e(t_map_data *d)
{
	int	a;

	a = d->is_againt_wall;
	if (a && ft_move_is_valid(d, &(d->map[d->pos_y - 1][d->pos_x])))
		d->dir = 'N';
	else if (a && ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x + 1])))
		;
	else if (a && ft_move_is_valid(d, &(d->map[d->pos_y + 1][d->pos_x])))
		d->dir = 'S';
	else if (a && ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x - 1])))
		d->dir = 'W';
	else if (a)
		d->no_move_possible = 1;
	else if (ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x + 1])))
		;
	else
		d->no_move_possible = 1;
}

void	ft_sub_checker_chang_dir_l_s(t_map_data *d)
{
	if (ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x + 1])))
		d->dir = 'E';
	else if (ft_move_is_valid(d, &(d->map[d->pos_y + 1][d->pos_x])))
		;
	else if (ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x - 1])))
		d->dir = 'W';
	else if (ft_move_is_valid(d, &(d->map[d->pos_y - 1][d->pos_x])))
		d->dir = 'N';
	else
		d->no_move_possible = 1;
}

void	ft_sub_checker_chang_dir_l_w(t_map_data *d)
{
	if (ft_move_is_valid(d, &(d->map[d->pos_y + 1][d->pos_x])))
		d->dir = 'S';
	else if (ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x - 1])))
		;
	else if (ft_move_is_valid(d, &(d->map[d->pos_y - 1][d->pos_x])))
		d->dir = 'N';
	else if (ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x + 1])))
		d->dir = 'E';
	else
		d->no_move_possible = 1;
}

void	ft_sub_checker_chang_dir_l_n(t_map_data *d)
{
	if (ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x - 1])))
		d->dir = 'W';
	else if (ft_move_is_valid(d, &(d->map[d->pos_y - 1][d->pos_x])))
		;
	else if (ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x + 1])))
		d->dir = 'E';
	else if (ft_move_is_valid(d, &(d->map[d->pos_y + 1][d->pos_x])))
		d->dir = 'S';
	else
		d->no_move_possible = 1;
}

int	ft_follow_wall_left(t_map_data *d, int nb)
{
	int	i;

	i = 0;
	if (ft_is_againt_wall(d))
		ft_set_dir_against_wall(d, 0);
	while (i == 0 || d->nb_pass != 3)
	{
		if (i == nb && i != 0)
			ft_rotate_dir_left(d);
		if (d->dir == 'E' || d->dir == 'S' || d->dir == 'W' || d->dir == 'N')
			if (ft_check_out(d))
				return (1);
		ft_sub_follow_wall_left(d);
		if (d->no_move_possible)
			return (0);
		ft_move(d, 0);
		if (d->pos_x == d->x_start && d->pos_y == d->y_start)
			d->nb_pass += 1;
		i++;
	}
	return (0);
}
