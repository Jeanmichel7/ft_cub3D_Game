/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_extern_wall_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:10:38 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_check_up_down(t_map_data *d, char **map, int i, int j)
{
	int	i_max;
	int	k;

	k = 0;
	while (map && map[k])
		k++;
	i_max = k - 1;
	if (i == 0 && map[i][j] == '0')
	{
		d->pos_x = j;
		d->pos_y = i;
		return (1);
	}
	else if (i == i_max && map[i][j] == '0')
	{
		d->pos_x = j;
		d->pos_y = i;
		return (1);
	}
	return (0);
}

int	ft_check_sub_ext_wall(t_map_data *d, char **map, int i)
{
	int	j;

	j = -1;
	while (map && map[i] && map[i][++j])
	{
		if (ft_check_up_down(d, map, i, j))
			return (1);
	}
	if (map[i][0] == '0' || map[i][ft_strlen(map[i]) - 1] == '0')
	{
		if (map[i][0] == '0')
			d->pos_x = 0;
		else
			d->pos_x = ft_strlen(map[i]) - 1;
		d->pos_y = i;
		return (1);
	}
	return (0);
}

int	ft_check_ext_wall(t_map_data *d)
{
	int		i;
	char	**map;

	map = d->map;
	i = 0;
	while (map && map[i])
	{
		if (ft_check_sub_ext_wall(d, map, i))
			return (1);
		i++;
	}
	return (0);
}
