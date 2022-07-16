/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:21:13 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/16 22:11:53 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_fill_caract(t_data *data, char **line_splited, char *line)
{
	char	*str1;
	char	*str2;
	int		len;

	str1 = line_splited[0];
	str2 = line_splited[1];
	len = ft_strlen(line_splited[0]);
	if (len == 1)
		ft_sub_fill_color(data, str1, str2, line);
	if (len < 3)
		ft_sub_fill_texture(data, str1, str2, line);
	else if (ft_map_begin(line) && data->is_map_started == 0)
	{
		data->is_map_started = 1;
		ft_copy_map(line, data);
	}
	else
	{
		printf("Error\nInvalid line '%s'\n", line);
		exit (0);
	}
}

int	ft_check_all_caract(t_data *data)
{
	if (data->texture_N == NULL || data->texture_S == NULL
		|| data->texture_W == NULL || data->texture_E == NULL
		|| data->color_floor == -1 || data->color_ceiling == -1
		|| data->is_map_started == 0)
		printf("Error\n");
	if (data->is_map_started == 0)
		printf("Missing map\n");
	if (data->texture_N == NULL)
		printf("Missing North texture\n");
	if (data->texture_S == NULL)
		printf("Missing South texture\n");
	if (data->texture_E == NULL)
		printf("Missing East texture\n");
	if (data->texture_W == NULL)
		printf("Missing West texture\n");
	if (data->color_ceiling == -1)
		printf("Missing ceil color\n");
	if (data->color_floor == -1)
		printf("Missing floor color\n");
	if (data->texture_N == NULL || data->texture_S == NULL
		|| data->texture_W == NULL || data->texture_E == NULL
		|| data->color_floor == -1 || data->color_ceiling == -1
		|| data->is_map_started == 0)
		return (1);
	return (0);
}

int	ft_empty_line(char *line)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (line && line[i])
	{
		if (line[i] == ' ' || (line[i] >=9 && line[i] <= 13))
			c++;
		i++;
	}
	if(i == c)
		return (1);
	return (0);
}

int	ft_checker_line(char *line, t_data *data)
{
	char	**line_splited;

	if (line && line[0] == '\0')
		return (0);
	if (ft_empty_line(line))
	{
		printf("Error\nSpace or tab in empty line\n");
		exit(0);
	}
	line_splited = ft_split(line, ' ');
	if (line_splited == NULL)
		free(line_splited);
	else if (ft_map_begin(line) && data->is_map_started == 0)
	{
		data->is_map_started = 1;
		ft_copy_map(line, data);
		ft_free_tab(line_splited);
		return (1);
	}
	else if (ft_nb_section_split(line_splited) >= 2)
		ft_fill_caract(data, line_splited, line);
	ft_free_tab(line_splited);
	return (0);
}

int	ft_parsing(t_data *data)
{
	char	*line;

	line = get_next_line(data->fd);
	while (line)
	{
		if (!ft_checker_line(line, data))
			free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	if (ft_check_all_caract(data))
		exit(0);
	return (0);
}
