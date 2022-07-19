/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:34:26 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/19 16:32:26 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	manage_keys(int key, t_data *data)
{
	if (key == 65307 || key == 53)
		ft_exit_game(data);
	return (0);
}

int	ft_press_key(int key, t_data *data)
{
	if (key == 13)
		data->forward = 1;
	if (key == 1)
		data->backward = 1;
	if (key == 2)
		data->right = 1;
	if (key == 0)
		data->left = 1;
	if (key == 123)
		data->rotate_right = 1;
	if (key == 124)
		data->rotate_left = 1;
	return (0);
}

int	ft_release_key(int key, t_data *data)
{
	(void)key;
	data->forward = 0;
	data->backward = 0;
	data->right = 0;
	data->left = 0;
	data->rotate_right = 0;
	data->rotate_left = 0;
	return (0);
}
