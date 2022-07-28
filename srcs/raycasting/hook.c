/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:55:08 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/21 14:37:14 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_key_press(int keycode, t_data *data)
{
	t_key	*key;

	key = &data->key;
	if (keycode == MOVE_LEFT)
		key->move_left = 1;
	if (keycode == MOVE_RIGHT)
		key->move_right = 1;
	if (keycode == FORWARD)
		key->move_forward = 1;
	if (keycode == BACKWARD)
		key->move_back = 1;
	if (keycode == ROTATE_LEFT)
		key->rotate_left = 1;
	if (keycode == ROTATE_RIGHT)
		key->rotate_right = 1;
	if (keycode == EXIT)
		ft_exit_game(data);
	data->keycode = keycode;
	return (0);
}

int	ft_key_release(int keycode, t_data *data)
{
	t_key	*key;

	key = &data->key;
	if (keycode == MOVE_LEFT)
		key->move_left = 0;
	if (keycode == MOVE_RIGHT)
		key->move_right = 0;
	if (keycode == FORWARD)
		key->move_forward = 0;
	if (keycode == BACKWARD)
		key->move_back = 0;
	if (keycode == ROTATE_LEFT)
		key->rotate_left = 0;
	if (keycode == ROTATE_RIGHT)
		key->rotate_right = 0;
	return (0);
}
