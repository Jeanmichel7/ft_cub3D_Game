/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_wall_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:53:34 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_rotate_dir_left(t_map_data *d)
{
	int	a;

	a = d->is_againt_wall;
	if (!a && ft_move_is_valid(d, &(d->map[d->pos_y - 1][d->pos_x])))
		d->dir = 'N';
	else if (!a && ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x + 1])))
		;
	else if (!a && ft_move_is_valid(d, &(d->map[d->pos_y + 1][d->pos_x])))
		d->dir = 'S';
	else if (!a && ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x - 1])))
		d->dir = 'W';
}

void	ft_rotate_dir_right(t_map_data *d)
{
	int	a;

	a = d->is_againt_wall;
	if (!a && ft_move_is_valid(d, &(d->map[d->pos_y + 1][d->pos_x])))
		d->dir = 'S';
	else if (!a && ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x + 1])))
		;
	else if (!a && ft_move_is_valid(d, &(d->map[d->pos_y - 1][d->pos_x])))
		d->dir = 'N';
	else if (!a && ft_move_is_valid(d, &(d->map[d->pos_y][d->pos_x - 1])))
		d->dir = 'W';
}

void	ft_sub_follow_wall_left(t_map_data *d)
{
	if (d->dir == 'E')
		ft_sub_checker_chang_dir_l_e(d);
	else if (d->dir == 'S')
		ft_sub_checker_chang_dir_l_s(d);
	else if (d->dir == 'W')
		ft_sub_checker_chang_dir_l_w(d);
	else if (d->dir == 'N')
		ft_sub_checker_chang_dir_l_n(d);
}

void	ft_sub_follow_wall_right(t_map_data *d)
{
	if (d->dir == 'E')
		ft_sub_checker_chang_dir_r_e(d);
	else if (d->dir == 'S')
		ft_sub_checker_chang_dir_r_s(d);
	else if (d->dir == 'W')
		ft_sub_checker_chang_dir_r_w(d);
	else if (d->dir == 'N')
		ft_sub_checker_chang_dir_r_n(d);
}
