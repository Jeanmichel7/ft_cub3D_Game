/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 01:30:17 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/22 00:28:19 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_fill_map(t_data *data, t_list *list)
{
	int		i;

	data->map.tab = malloc(sizeof(char *) * (data->map.height + 1));
	i = 0;
	while (list)
	{
		data->map.tab[i] = malloc(sizeof(char) * \
		(ft_strlen(list->content) + 1));
		ft_strlcpy(data->map.tab[i], list->content, \
		ft_strlen(list->content) + 1);
		list = list->next;
		i++;
	}
	data->map.tab[i] = NULL;
}

int	ft_check_map_line(char *line, t_data *data)
{
	int		i;
	char	c;

	i = 0;
	if (line)
		c = line[i];
	while (line && c)
	{
		if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' \
		&& c != 'W' && c != ' ' && c != 'D' && c != 'B' && c != 'M' \
		&& c != 'L' && c != '2')
		{
			printf("Error\nInvalid caracter '%c' on the map\n", c);
			return (1);
		}
		if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			data->player_spawn_dir = c;
		i++;
		c = line[i];
	}
	return (0);
}

void	ft_sub_copy_map(char *line, t_data *data, t_list *list)
{
	char	*line_temp;

	if (ft_check_map_line(line, data))
		exit(0);
	if ((int)ft_strlen(line) > data->map.width)
		data->map.width = (int)ft_strlen(line);
	if (data->map.height != 0)
	{
		line_temp = malloc(sizeof(char) * (ft_strlen(line) + 1));
		ft_strlcpy(line_temp, line, (ft_strlen(line) + 1));
		ft_lstadd_back(&list, ft_lstnew(line_temp));
		free(line);
	}
	data->map.height++;
}

void	ft_copy_map(char *line, t_data *data)
{
	t_list	*list;

	data->map.width = ft_strlen(line);
	list = ft_lstnew(line);
	while (line && line[0] != '\0')
	{
		ft_sub_copy_map(line, data, list);
		line = get_next_line(data->fd);
	}
	free(line);
	ft_fill_map(data, list);
	ft_free_list(list);
	if (ft_check_map(data))
		exit (0);
}
