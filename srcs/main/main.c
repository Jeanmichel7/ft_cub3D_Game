/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:38:35 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/14 03:28:24 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_close_and_free(data);
	exit(0);
	return (0);
}

int	manage_keys(int key, t_data *data)
{
	if (key == 65307 || key == 53)
		ft_exit_game(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data);
	if (ft_checker(argc, argv, &data) || ft_parsing(&data))
		return (ft_free_texture(&data));
	ft_printdata(&data);
	ft_init_display(&data);
	mlx_key_hook(data.mlx_win, manage_keys, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_exit_game, &data);
	mlx_loop(data.mlx);
	return (0);
}
