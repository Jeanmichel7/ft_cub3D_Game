/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 23:37:10 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/13 23:37:10 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_out(t_map_data *d)
{
	//check en fct lonheur ligne (int)ft_strlen(d->map[posY]) - 1
	if (d->dir == 'E')
	{
		//printf("\n\nlen line : %d\n", (int)ft_strlen(d->map[d->posY - 1]) - 1);
		//printf("posX : %d\n\n\n", d->posX);

		if (d->posY == 0)
			return (1);
		else if (d->posX > (int)ft_strlen(d->map[d->posY]) - 1)
			return (1);
	}
	else if (d->dir == 'S')
	{
		//printf("\n\nlen line : %d\n", (int)ft_strlen(d->map[d->posY + 1]) - 1);
		//printf("posX : %d\n\n\n", d->posX);
		if (d->posY == d->height - 1)
			return (1);
		else if (d->posX > (int)ft_strlen(d->map[d->posY + 1]) - 1)
			return (1);
	}
	else if (d->dir == 'W' && d->posX == 0)
		return (1);
	else if (d->dir == 'N')
	{
		if(d->posY == 0)
			return (1);
		//if (d->posX == (int)ft_strlen(d->map[d->posY - 1]) - 1 && d->map[d->posY - 1][d->posX] != '1')
		//{
		//	printf("lui ici\n");
		//	return (1);
		//}
		else if (d->posX > (int)ft_strlen(d->map[d->posY - 1]) - 1)
			return (1);
	}
	return (0);
}

int	ft_move_is_valid(char c)
{
	if (c == '\0')
	{
		printf("Map is open\n");
		//free;
		exit(0);
	}
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0')
		return (1);
	return (0);
}

void	ft_move(t_map_data *d)
{
	if (d->dir == 'E')
		d->posX += 1;
	else if (d->dir == 'S')
		d->posY += 1;
	else if (d->dir == 'W')
		d->posX -= 1;
	else if (d->dir == 'N')
		d->posY -= 1;
}