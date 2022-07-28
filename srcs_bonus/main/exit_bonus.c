/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:38:32 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/27 16:17:15 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	ft_close_and_free(data);
	exit(0);
}
