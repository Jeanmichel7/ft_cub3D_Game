/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:37:11 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/14 00:37:11 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_check_space_in_color(char *line)
{
	char	**tab;
	int		i;

	tab = ft_split(line, ' ');
	i = 0;
	while (tab && tab[i])
		i++;
	if (i > 2)
	{
		ft_free_tab(tab);
		return (1);
	}
	ft_free_tab(tab);
	return (0);
}

char	*ft_line_color(char *line)
{
	int		i;
	char	*new_line;
	int		i_start;

	i = 0;
	while (line && line[i] && (line[i] == 'F' || line[i] == 'C' \
	|| line[i] == ' '))
		i++;
	i_start = i - 1;
	i = 0;
	while (line && line[i])
		i++;
	new_line = line + i_start;
	return ((new_line));
}

char	**ft_trim_tab(char **tab)
{
	char	**new_tab;
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	new_tab = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tab && tab[i])
	{
		new_tab[i] = ft_strtrim(tab[i], " ");
		free(tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	free(tab);
	return (new_tab);
}

void	ft_sub_sub_fill_color(t_data *data, char *str1, char *str2,
char *line)
{
	char	**tab_color;
	char	*line_data;

	if (ft_check_space_in_color(line))
		line_data = ft_line_color(line);
	else
		line_data = str2;
	if (ft_check_comma(line_data))
	{
		tab_color = ft_split(line_data, ',');
		tab_color = ft_trim_tab(tab_color);
		if (str1[0] == 'F')
			ft_parse_color(&(data->floor), tab_color);
		else if (str1[0] == 'C')
			ft_parse_color(&(data->ceiling), tab_color);
		ft_free_tab(tab_color);
	}
	else
	{
		if (str1[0] == 'F')
			data->texture[TEXTURE_FLOOR].use_color = 0;
		else if (str1[0] == 'C')
			data->texture[TEXTURE_CEIL].use_color = 0;
	}
}

void	ft_sub_fill_color(t_data *data, char *str1, char *str2, char *line)
{
	if (!(data->is_map_started) && (str1[0] == 'F' || str1[0] == 'C'))
	{
		ft_sub_sub_fill_color(data, str1, str2, line);
	}
	else if (data->is_map_started && (str1[0] == 'F' || str1[0] == 'C'))
	{
		printf("Error\nColor is declared after map (pas bien)\n");
		exit(0);
	}
	else if (!(data->is_map_started) && ft_map_begin(line))
	{
		data->is_map_started = 1;
		ft_copy_map(line, data);
	}
	else if (str1[0] != 'N' && str1[0] != 'S' && str1[0] != 'E'
		&& str1[0] != 'W')
	{
		printf("Error\nInvalid line '%s'\n", line);
		exit (0);
	}
}
