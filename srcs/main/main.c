/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:38:35 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/19 16:33:37 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data);
	if (ft_checker(argc, argv, &data) || ft_parsing(&data))
		return (ft_free_texture(&data));
	ft_replace_space(&data);

	ft_init_display(&data);
	ft_printdata(&data);
	
	mlx_key_hook(data.mlx_win, manage_keys, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_exit_game, &data);
	mlx_hook(data.mlx_win, 02, (1L<<0), ft_press_key, &data);
	mlx_hook(data.mlx_win, 03, (1L<<1), ft_release_key, &data);
	mlx_loop_hook(data.mlx, ft_raycaster, &data);

	mlx_loop(data.mlx);
	return (0);
}
