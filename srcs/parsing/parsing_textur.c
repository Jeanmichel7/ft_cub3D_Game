/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:38:52 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/14 00:38:52 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_check_location_texture(t_data *data, char *str1)
{
	if (data->is_map_started && \
	(str1[0] == 'N' || str1[0] == 'S' || str1[0] == 'W' || str1[0] == 'E'))
	{
		printf("Texture is declared after map (pas bien)\n");
		exit(0);
	}
}

void	ft_sub_fill_texture(t_data *data, char *str1, char *str2, char *line)
{
	ft_check_location_texture(data, str1);
	if (str1[0] == 'N' && (str1[1] == '\0' \
	|| (str1[1] == 'O' && str1[2] == '\0')))
		ft_sub_fill_caract(&(data->texture_N), str2);
	else if (str1[0] == 'S' && (str1[1] == '\0' \
	|| (str1[1] == 'O' && str1[2] == '\0')))
		ft_sub_fill_caract(&(data->texture_S), str2);
	else if (str1[0] == 'W' && (str1[1] == '\0' \
	|| (str1[1] == 'E' && str1[2] == '\0')))
		ft_sub_fill_caract(&(data->texture_W), str2);
	else if (str1[0] == 'E' && (str1[1] == '\0' \
	|| (str1[1] == 'A' && str1[2] == '\0')))
		ft_sub_fill_caract(&(data->texture_E), str2);
	else if (ft_map_begin(line) && data->is_map_started == 0)
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
