/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_border_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:44:17 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/13 17:44:17 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_player_spawn(t_map_data *d, t_data *data)
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
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' \
			|| map[i][j] == 'E')
			{
				d->posY = i;
				d->posX = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_map_border(t_map_data *map_data)
{
	if (ft_follow_wall(map_data))
		return (1);
	return (0);
}

void	ft_init_map_data(t_map_data *map_data, t_data *data)
{
	map_data->map = data->map.tab;
	map_data->posX = -1;
	map_data->posY = -1;
	map_data->x_start = -1;
	map_data->y_start = -1;
	map_data->dir = 'E';
	map_data->height = data->map.height;
	map_data->width = data->map.width;
	map_data->nb_pass = 0;
	map_data->no_move_possible = 0;
	map_data->is_againt_wall = 0;
}

int	ft_check_map(t_data *data)
{
	t_map_data	map_data;

	ft_init_map_data(&map_data, data);
	if (ft_check_player_spawn(&map_data, data))
	{
		printf("Error\nNo spawner\n");
		exit(0);
	}
	if (ft_check_map_border(&map_data))
	{
		printf("Error\nMap is open in (%d, %d)\n", map_data.posX, map_data.posY);
		ft_print_map(&map_data);
		return (1);
	}
	return (0);
}
