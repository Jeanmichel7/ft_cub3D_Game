/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:25:30 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/14 00:25:30 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_set_orientation(t_data *d)
{
	if (d->player_spawn_dir == 'N')
		d->ray_data.orientation = 90;
	else if (d->player_spawn_dir == 'W')
		d->ray_data.orientation = 180; 
	else if (d->player_spawn_dir == 'S')
		d->ray_data.orientation = 270; 
	else if (d->player_spawn_dir == 'E')
		d->ray_data.orientation = 0; 
}

void	ft_sub_replace_space(t_data *data, int i, int j)
{
	if (data->player_spawn_x == -1)
	{
		data->player_spawn_x = j;
		data->player_spawn_y = i;
		data->player_spawn_dir = data->map.tab[i][j];
		ft_set_orientation(data);
	}
	else
	{
		printf("Error\nPlayer has more than one spawner\n");
		exit(0);
	}
}

void	ft_replace_space(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	map = data->map.tab;
	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map && map[i] && map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' \
			|| map[i][j] == 'E')
			{
				ft_sub_replace_space(data, i, j);
			}
			j++;
		}
		i++;
	}
}
