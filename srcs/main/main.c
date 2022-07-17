/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:38:35 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/17 19:11:32 by jrasser          ###   ########.fr       */
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

	ft_raycaster(&data);

	mlx_loop(data.mlx);
	return (0);
}
