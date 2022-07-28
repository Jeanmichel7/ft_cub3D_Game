/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:10:38 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/21 18:04:04 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_check_miss_caract(t_data *data)
{
	if (data->texture[0].path == NULL || data->texture[1].path == NULL
		|| data->texture[2].path == NULL || data->texture[3].path == NULL
		|| (data->floor == -1 && data->texture[TEXTURE_FLOOR].use_color == 1)
		|| (data->texture[TEXTURE_FLOOR].use_color == 0
			&& !(data->texture[TEXTURE_FLOOR].path))
		|| (data->ceiling == -1 && data->texture[TEXTURE_CEIL].use_color == 1)
		|| (data->texture[TEXTURE_CEIL].use_color == 0
			&& !(data->texture[TEXTURE_CEIL].path))
		|| data->is_map_started == 0)
		return (1);
	return (0);
}

int	ft_nb_section_split(char **line_splited)
{
	int	i;

	i = 0;
	while (line_splited && line_splited[i])
		i++;
	return (i);
}

int	ft_check_format_color(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab && tab[i])
	{
		j = 0;
		while (tab && tab[i] && tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
			{
				printf("Error\nNon digit value : '%s'\n", tab[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_parse_color(int *color, char **tab)
{
	int	red;
	int	green;
	int	blue;

	if (ft_check_format_color(tab))
		exit(0);
	red = ft_atoi(tab[0]);
	green = ft_atoi(tab[1]);
	blue = ft_atoi(tab[2]);
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 \
	|| blue > 255)
	{
		printf("Error\nValue not between 0 and 255\n");
		exit(0);
	}
	*color = red << 16 | green << 8 | blue;
}

int	ft_check_comma(char	*str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}
