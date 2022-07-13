/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:29:59 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/13 02:04:01 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void ft_take_player_pos(t_data *data, char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N')
				data->player_spawn_dir = 'N';
			if (map[y][x] == 'S')
				data->player_spawn_dir = 'S';
			if (map[y][x] == 'E')
				data->player_spawn_dir = 'E';
			if (map[y][x] == 'W')
				data->player_spawn_dir = 'W';
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
			{
				data->player_spawn_x = x;
				data->player_spawn_y = y;
			}
			x++;
		}
		y++;
	}
}

int ft_parse_map(t_data *data, char *line, int fd)
{
	char *map;
	char *temp;
	char sep[] = {'\n', 0};

	temp = line;
	line = ft_strjoin(line, (char const *)&sep);
	free(temp);
	map = ft_substr(line, 0, ft_strlen(line));
	while (line)
	{
		temp = line;
		line = get_next_line(fd);
		if (line == NULL)
			break;
		free(temp);
		temp = line;
		line = ft_strjoin(line, (char const *)&sep);
		free(temp);
		temp = map;
		map = ft_strjoin(map, line);
		free(temp);
	}
	data->map.tab = ft_split(map, '\n');
	ft_take_player_pos(data, data->map.tab);
	return (0);
}