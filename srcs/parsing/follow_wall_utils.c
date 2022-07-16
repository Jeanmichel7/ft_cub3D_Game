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

#include "../../include/cub3d.h"

int	ft_check_out(t_map_data *d)
{
	if (d->dir == 'E')
	{
		if (d->posY == 0)
			return (1);
		else if (d->posX > (int)ft_strlen(d->map[d->posY]) - 1)
			return (1);
	}
	else if (d->dir == 'S')
	{
		if (d->posY == d->height - 1)
			return (1);
		else if (d->posX > (int)ft_strlen(d->map[d->posY + 1]) - 1)
			return (1);
	}
	else if (d->dir == 'W' && d->posX == 0)
		return (1);
	else if (d->dir == 'N')
	{
		if (d->posY == 0)
			return (1);
		else if (d->posX > (int)ft_strlen(d->map[d->posY - 1]) - 1)
			return (1);
	}
	return (0);
}

int	ft_move_is_valid(t_map_data *map_data, char *c)
{
	if (*c == '\0')
	{
		printf("Error\nMap is open in (%d, %d)\n", map_data->posX, \
		map_data->posY);
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
	if (d->map[d->posY][d->posX + 1] == '1')
		return (1);
	return (0);
}

void	ft_move(t_map_data *d)
{
	if (d->dir == 'E')
		d->posX += 1;
	else if (d->dir == 'S')
		d->posY += 1;
	else if (d->dir == 'W')
		d->posX -= 1;
	else if (d->dir == 'N')
		d->posY -= 1;
	if (d->is_againt_wall == 0 && ft_is_againt_wall(d))
	{
		d->is_againt_wall = 1;
		d->x_start = d->posX;
		d->y_start = d->posY;
		d->dir = 'S';
	}
}
