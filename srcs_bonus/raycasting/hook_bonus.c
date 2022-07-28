/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:55:08 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 14:58:57 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

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
	if (keycode == ACTION)
		key->use = 1;
	if (keycode == SPEED)
		data->move_speed *= 2;
	if (keycode == EXIT)
		ft_exit_game(data);
	data->keycode = keycode;
	return (0);
}

int	ft_key_release(int keycode, t_data *data)
{
	t_key	*key;

	key = &data->key;
	(void)keycode;
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
	if (keycode == SPEED)
		data->move_speed /= 2;
	if (keycode == ACTION)
		key->use = 0;
	return (0);
}

int	ft_mouse(int x, int y, t_data *data)
{
	static int	old_x;
	static int	first;

	(void)y;
	if (first == 0)
	{
		old_x = x;
		first = 1;
	}
	if (old_x - x < 0)
		data->key.mouse_rotate_left = abs(x - old_x);
	if (old_x - x > 0)
		data->key.mouse_rotate_right = abs(x - old_x);
	old_x = x;
	return (0);
}
