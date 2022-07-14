/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:10:38 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/14 02:26:56 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_sub_fill_caract(char **caract, char *str)
{
	if (*caract != NULL)
		free(*caract);
	*caract = malloc(sizeof(char) * (ft_strlen(str) + 1));
	ft_strlcpy(*caract, str, ft_strlen(str) + 1);
}

int	ft_nb_section_split(char **line_splited)
{
	int	i;

	i = 0;
	while (line_splited && line_splited[i])
		i++;
	return (i);
}

void	ft_parse_color(int *color, char **tab)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(tab[0]);
	green = ft_atoi(tab[1]);
	blue = ft_atoi(tab[2]);
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
	if (count < 2 || count > 2)
		return (1);
	return (0);
}
