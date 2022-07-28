/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 23:37:10 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/13 23:37:10 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_check_out(t_map_data *d)
{
	if (d->dir == 'E')
	{
		if (d->pos_y == 0)
			return (1);
		else if (d->pos_x > (int)ft_strlen(d->map[d->pos_y]) - 1)
			return (1);
	}
	else if (d->dir == 'S')
	{
		if (d->pos_y == d->height - 1)
			return (1);
		else if (d->pos_x > (int)ft_strlen(d->map[d->pos_y + 1]) - 1)
			return (1);
	}
	else if (d->dir == 'W' && d->pos_x == 0)
		return (1);
	else if (d->dir == 'N')
	{
		if (d->pos_y == 0)
			return (1);
		else if (d->pos_x > (int)ft_strlen(d->map[d->pos_y - 1]) - 1)
			return (1);
	}
	return (0);
}

int	ft_move_is_valid(t_map_data *map_data, char *c)
{
	if (*c == '\0')
	{
		printf("Error\nMap is open in (%d, %d)\n", map_data->pos_x, \
		map_data->pos_y);
		ft_print_map(map_data);
		exit(0);
	}
	if (*c == ' ')
		*c = '0';
	if (*c == 'N' || *c == 'S' || *c == 'E' || *c == 'W' || *c == '0')
		return (1);
	return (0);
}

int	ft_is_againt_wall(t_map_data *d)
{
	if (d->dir == 'E' && d->map[d->pos_y][d->pos_x + 1] == '1')
		return (1);
	else if (d->dir == 'S' && d->map[d->pos_y + 1][d->pos_x] == '1')
		return (1);
	else if (d->dir == 'W' && d->map[d->pos_y][d->pos_x - 1] == '1')
		return (1);
	else if (d->dir == 'N' && d->map[d->pos_y - 1][d->pos_x] == '1')
		return (1);
	return (0);
}

void	ft_set_dir_against_wall(t_map_data *d, int move_against_wall)
{
	if (d->is_againt_wall == 0 && ft_is_againt_wall(d))
	{
		d->is_againt_wall = 1;
		d->x_start = d->pos_x;
		d->y_start = d->pos_y;
		if (move_against_wall == 0)
			d->dir = 'S';
		else
			d->dir = 'N';
	}
}

void	ft_move(t_map_data *d, int move_against_wall)
{
	if (d->dir == 'E')
		d->pos_x += 1;
	else if (d->dir == 'S')
		d->pos_y += 1;
	else if (d->dir == 'W')
		d->pos_x -= 1;
	else if (d->dir == 'N')
		d->pos_y -= 1;
	ft_set_dir_against_wall(d, move_against_wall);
	d->nb_move += 1;
}
