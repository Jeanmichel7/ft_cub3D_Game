/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:34:26 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/17 18:43:41 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	manage_keys(int key, t_data *data)
{
	if (key == 65307 || key == 53)
		ft_exit_game(data);

	printf("key : %d\n", key);
	
	if (key == 'a')
	{
		ft_fill_line(data);
	}

	return (0);
}
