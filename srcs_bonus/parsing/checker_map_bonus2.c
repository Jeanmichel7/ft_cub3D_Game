/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:44:17 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/28 15:09:33 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_check_map_border(t_map_data *d, t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 4)
	{
		ret = ft_follow_wall_left(d, i);
		if (ret)
			return (1);
		ft_init_map_data(d, data);
		ft_check_player_spawn(d, data, 0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ret = ft_follow_wall_right(d, i);
		if (ret)
			return (1);
		ft_init_map_data(d, data);
		ft_check_player_spawn(d, data, 0);
		i++;
	}
	return (0);
}

int	ft_check_map(t_data *data)
{
	t_map_data	map_data;
	int			ret;

	ft_init_map_data(&map_data, data);
	if (ft_check_player_spawn(&map_data, data, 1))
	{
		printf("Error\nNo spawner\n");
		exit(0);
	}
	ret = ft_check_map_border(&map_data, data);
	if (ret)
	{
		printf("Error\nMap open in (%d, %d)\n\n", map_data.pos_x, map_data.pos_y);
		ft_print_map(&map_data);
		return (1);
	}
	if (ft_check_ext_wall(&map_data))
	{
		printf("Error\nMap is not close in (%d, %d)\n\n", \
		map_data.pos_x, map_data.pos_y);
		ft_print_map(&map_data);
		exit (0);
	}
	ft_print_map(&map_data);
	return (0);
}
