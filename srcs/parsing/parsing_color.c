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

#include "../../include/cub3d.h"

void	ft_sub_sub_fill_color(t_data *data, char *str1, char *str2)
{
	char	**tab_color;

	tab_color = NULL;
	if (ft_check_comma(str2))
	{
		printf("Invalide floor color because you suck! Need ',' between ");
		printf("colors and need 3 args!\n");
		exit(0);
	}
	tab_color = ft_split(str2, ',');
	if (str1[0] == 'F')
		ft_parse_color(&(data->color_floor), tab_color);
	else if (str1[0] == 'C')
		ft_parse_color(&(data->color_ceiling), tab_color);
	ft_free_tab(tab_color);
}

void	ft_sub_fill_color(t_data *data, char *str1, char *str2, char *line)
{
	if (!(data->is_map_started) && (str1[0] == 'F' || str1[0] == 'C'))
	{
		ft_sub_sub_fill_color(data, str1, str2);
	}
	else if (data->is_map_started && (str1[0] == 'F' || str1[0] == 'C'))
	{
		printf("Color is declared after map (pas bien)\n");
		exit(0);
	}
	else if (!(data->is_map_started) && ft_map_begin(line))
	{
		data->is_map_started = 1;
		ft_copy_map(line, data);
	}
	else
	{
		printf("Invalid line '%s'\n", line);
		exit (0);
	}
}
