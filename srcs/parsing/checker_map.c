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
				d->pos_y = i;
				d->pos_x = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_init_map_data(t_map_data *map_data, t_data *data)
{
	map_data->map = data->map.tab;
	map_data->pos_x = -1;
	map_data->pos_y = -1;
	map_data->x_start = -1;
	map_data->y_start = -1;
	map_data->dir = 'E';
	map_data->height = data->map.height;
	map_data->width = data->map.width;
	map_data->nb_pass = 0;
	map_data->nb_move = 0;
	map_data->no_move_possible = 0;
	map_data->is_againt_wall = 0;
}

int	ft_check_map_border(t_map_data *d, t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 4)
	{
		ret = ft_follow_wall_left(d, i);
		if (ret)
			return (1);
		ft_init_map_data(d, data);
		ft_check_player_spawn(d, data);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ret = ft_follow_wall_right(d, i);
		if (ret)
			return (1);
		ft_init_map_data(d, data);
		ft_check_player_spawn(d, data);
		i++;
	}
	return (0);
}

int	ft_check_sub_map(t_map_data *map_data, t_data *data)
{
	int			ret;

	ft_init_map_data(map_data, data);
	if (ft_check_player_spawn(map_data, data))
	{
		printf("Error\nNo spawner\n");
		exit(0);
	}
	ret = ft_check_map_border(map_data, data);
	if (ret)
	{
		printf("Error\nMap is open in (%d, %d)\n\n", \
		map_data->pos_x, map_data->pos_y);
		ft_print_map(map_data);
		return (1);
	}
	return (0);
}

int	ft_check_map(t_data *data)
{
	t_map_data	map_data;

	if (ft_check_sub_map(&map_data, data))
		return (1);
	if (ft_check_ext_wall(&map_data))
	{
		printf("Error\nMap is not close in (%d, %d)\n\n", \
		map_data.pos_x, map_data.pos_y);
		ft_print_map(&map_data);
		exit (0);
	}
	ft_print_map(&map_data);
	printf("\nTest Map 	\u2705 \n");
	return (0);
}
