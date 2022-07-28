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

#include "../../include/cub3d_bonus.h"

int	ft_check_door(char **map, int i, int j)
{
	int	ret;

	ret = 0;
	if (map[i - 1][j] == '1' && map[i + 1][j] == '1')
		ret = 1;
	if (map[i][j - 1] == '1' && map[i][j + 1] == '1')
		ret = 1;
	map[i][j] = '2';
	return (ret);
}

int	ft_checker_char(t_map_data *d, t_data *data, int i, int j)
{
	char		**map;
	static int	n = 0;

	map = data->map.tab;
	if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' \
	|| map[i][j] == 'E')
	{
		d->pos_y = i;
		d->pos_x = j;
		return (1);
	}
	else if (map[i][j] == 'D' && !(ft_check_door(map, i, j)))
	{
		printf("Error\nDoor is not between wall...dumbass\n");
		printf("Please check in (%d, %d)\n", i, j);
		exit(0);
	}
	else if (map[i][j] == 'B')
		ft_add_texture(data, j, i, &n);
	else if (map[i][j] == 'M')
		ft_add_texture_anime(data, j, i, &n);
	return (0);
}

int	ft_checker_pos(t_map_data *d, t_data *data, int i, int j)
{
	char	**map;

	map = data->map.tab;
	if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' \
	|| map[i][j] == 'E')
	{
		d->pos_y = i;
		d->pos_x = j;
		return (1);
	}
	return (0);
}

int	ft_check_player_spawn(t_map_data *d, t_data *data, int check_all)
{
	int		i;
	int		j;
	char	**map;
	int		is_spawn;

	is_spawn = 1;
	map = data->map.tab;
	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map && map[i] && map[i][j])
		{
			if (check_all)
			{
				if (ft_checker_char(d, data, i, j))
					is_spawn = 0;
			}
			else
				ft_checker_pos(d, data, i, j);
			j++;
		}
		i++;
	}
	return (is_spawn);
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
