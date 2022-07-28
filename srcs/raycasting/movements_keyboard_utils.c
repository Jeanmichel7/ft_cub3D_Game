/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_keyboard_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:39:08 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/27 19:43:31 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	ft_check_double_overflow(double value)
{
	if (value > 1)
		return (1);
	else if (value < -1)
		return (-1);
	return (value);
}
