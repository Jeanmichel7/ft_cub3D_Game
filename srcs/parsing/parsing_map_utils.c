/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:02:41 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/13 17:02:41 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_is_map_border(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && (line[i] == '1' || line[i] == ' ' \
	|| line[i] == '0'))
		i++;
	if (i == (int)ft_strlen(line))
		return (1);
	return (0);
}

int	ft_map_begin(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if ((line[i] == '1' || line[i] == ' ') \
		&& line[i + 1] && (line[i + 1] == '1' || line[i + 1] == ' ') \
		&& ft_is_map_border(line))
			return (1);
		i++;
	}
	return (0);
}
