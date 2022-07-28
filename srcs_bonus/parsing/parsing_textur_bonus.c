/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textur_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:54:38 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/21 16:54:38 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_check_location_texture(t_data *data, char *s1)
{
	if (data->is_map_started && \
	(s1[0] == 'N' || s1[0] == 'S' || s1[0] == 'W' || s1[0] == 'E'))
	{
		printf("Error\nTexture is declared after map (pas bien)\n");
		exit(0);
	}
}

void	ft_sub_fill_caract(char **caract, char *str)
{
	if (*caract != NULL)
		free(*caract);
	*caract = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strlcpy(*caract, str, ft_strlen(str) + 1);
}

void	ft_sub_fill_texture(t_data *data, char *s1, char *s2, char *line)
{
	ft_check_location_texture(data, s1);
	if (s1[0] == 'N' && (s1[1] == '\0' || (s1[1] == 'O' && s1[2] == '\0')))
		ft_sub_fill_caract(&(data->texture[0].path), s2);
	else if (s1[0] == 'S' && (s1[1] == '\0' || (s1[1] == 'O' && s1[2] == '\0')))
		ft_sub_fill_caract(&(data->texture[1].path), s2);
	else if (s1[0] == 'E' && (s1[1] == '\0' || (s1[1] == 'A' && s1[2] == '\0')))
		ft_sub_fill_caract(&(data->texture[2].path), s2);
	else if (s1[0] == 'W' && (s1[1] == '\0' || (s1[1] == 'E' && s1[2] == '\0')))
		ft_sub_fill_caract(&(data->texture[3].path), s2);
	else if (s1[0] == 'C' && s1[1] == '\0'
		&& data->texture[TEXTURE_CEIL].use_color == 0)
		ft_sub_fill_caract(&(data->texture[TEXTURE_CEIL].path), s2);
	else if (s1[0] == 'F' && s1[1] == '\0'
		&& data->texture[TEXTURE_FLOOR].use_color == 0)
		ft_sub_fill_caract(&(data->texture[TEXTURE_FLOOR].path), s2);
	else if (ft_map_begin(line) && data->is_map_started == 0)
	{
		data->is_map_started = 1;
		ft_copy_map(line, data);
	}
	else if (s1[0] != 'F' && s1[0] != 'C')
	{
		printf("Error\nInvalid line '%s'\n", line);
		exit (0);
	}
}
