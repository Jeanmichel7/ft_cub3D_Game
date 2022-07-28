/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:51:21 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/27 16:41:27 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_close_and_free(t_data *data)
{
	free(data->mlx);
	ft_free_texture(data);
	ft_free_tab(data->map.tab);
}

int	ft_free_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->textures_nb)
	{
		if (data->texture[i].is_copy > 1 || ft_is_not_sprite(data, i))
			free(data->texture[i].path);
		i++;
	}
	return (0);
}

void	ft_free_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
	free(temp);
	free(list);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_is_not_sprite(t_data *data, int i)
{
	if (data->texture[i].type != 'D' && data->texture[i].type != 'B' \
	&& data->texture[i].type != 'M' && data->texture[i].type != 'L')
		return (1);
	return (0);
}
