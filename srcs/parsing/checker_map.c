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

int	ft_check_player_spawn(t_data *data)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_start_following(t_map_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map && d->map[i])
	{
		j = 0;
		while (d->map && d->map[i] && d->map[i][j])
		{
			if (d->map[i][j] == '1' && i < d->height - 1 \
			&& d->map[i + 1][j] == '0')
			{
				d->y_start = i + 1;
				d->x_start = j;
				d->posY = i + 1;
				d->posX = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i == d->height && j == d->width)
		return (1);
	return (0);
}

int	ft_check_map_border(t_data *data)
{
	t_map_data	map_data;

	map_data.map = data->map.tab;
	map_data.posX = -1;
	map_data.posY = -1;
	map_data.x_start = -1;
	map_data.y_start = -1;
	map_data.dir = 'E';
	map_data.height = data->map.height;
	map_data.width = data->map.width;
	map_data.nb_pass = 0;
	if (ft_check_start_following(&map_data))
	{
		printf("Only wall...\n");
		//free();
		exit(0);
	}
	if (ft_follow_wall(&map_data))
		return (1);
	return (0);
}

int	ft_check_map(t_data *data)
{
	ft_replace_space(data);
	if (ft_check_player_spawn(data))
	{
		printf("No spawner\n");
		//free
		exit(0);
	}
	if (ft_check_map_border(data))
		return (1);
	// parcour mur
	return (0);
}
