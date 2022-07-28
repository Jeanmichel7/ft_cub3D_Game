/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:11:41 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/28 15:10:01 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_random_move(t_data *data, int i)
{
	static char	last_move = 'L';
	char		**map;
	double		x;
	double		y;
	double		delta;

	map = data->map.tab;
	x = data->sprite[i].x;
	y = data->sprite[i].y;
	delta = 0.01;
	if (x - delta > 1 && map[(int)y][(int)(x - 0.25 - delta)] != '1'
		&& map[(int)y][(int)(x - 0.25 - delta)] != 'D' && last_move == 'L')
	{
		last_move = 'L';
		data->sprite[i].x -= delta;
	}
	else if (map[(int)y][(int)(x + 0.25 + delta)] != '1'
		&& map[(int)y][(int)(x + 0.25 + delta)] != 'D')
	{
		data->sprite[i].x += delta;
		last_move = 'R';
	}
	else
		last_move = 'L';
}

float	ft_calc_dist_player_monster(t_data *data, int i)
{
	double	x_monster;
	double	y_monster;
	double	x_player;
	double	y_player;
	float	dist;

	x_monster = data->sprite[i].x;
	y_monster = data->sprite[i].y;
	x_player = data->ray_data.pos_x;
	y_player = data->ray_data.pos_y;
	if (fabs(x_monster - x_player) == (float)0)
		x_monster += 0.000001;
	if (fabs(y_monster - y_player) == (float)0)
		y_monster += 0.000001;
	dist = sqrtf(powf(x_monster - x_player, 2) + powf(y_monster - y_player, 2));
	return (dist);
}

void	ft_follow_player(t_data *data, int i)
{
	double	delta;
	double	x_monster;
	double	y_monster;
	double	x_player;
	double	y_player;

	x_monster = data->sprite[i].x;
	y_monster = data->sprite[i].y;
	x_player = data->ray_data.pos_x;
	y_player = data->ray_data.pos_y;
	delta = 0.02;
	if (x_player > x_monster + 0.8)
		data->sprite[i].x += delta;
	else if (x_player < x_monster - 0.8)
		data->sprite[i].x -= delta;
	if (y_player > y_monster + 0.8)
		data->sprite[i].y += delta;
	else if (y_player < y_monster - 0.8)
		data->sprite[i].y -= delta;
}

void	ft_remove_case(t_data *data, int i)
{
	char		**map;
	double		x;
	double		y;

	map = data->map.tab;
	x = data->sprite[i].x;
	y = data->sprite[i].y;
	map[(int)y][(int)x] = '0';
}

void	ft_move_enemi(t_data *data)
{
	int			i;
	float		dist;
	static int	is_remove_case = 0;

	i = 0;
	while (i < data->sprites_nb)
	{
		if (data->sprite[i].is_anim)
		{
			if (is_remove_case == 0)
				ft_remove_case(data, i);
			dist = ft_calc_dist_player_monster(data, i);
			if (dist < (float)3.5)
				ft_follow_player(data, i);
			else
				ft_random_move(data, i);
		}
		i++;
	}
	is_remove_case ++;
}
