/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:51:21 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/21 17:21:49 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
