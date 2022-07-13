/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:02:29 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/13 23:11:51 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_printdata(t_data *data)
{
	int	i;

	printf("           DATA             \n\n");
	if (data->texture_N != NULL)
	printf("texture_N : %s \n", data->texture_N);
	if (data->texture_S != NULL)
	printf("texture_S : %s \n", data->texture_S);
	if (data->texture_W != NULL)
	printf("texture_W : %s \n", data->texture_W);
	if (data->texture_E != NULL)
	printf("texture_E : %s \n", data->texture_E);
	
	printf("floor : %d \n", data->color_floor);
	printf("ceiling : %d \n", data->color_ceiling);
	printf("direction spawn player : %c \n", data->player_spawn_dir);
	printf("pos x player : %d \n", data->player_spawn_x); 
	printf("pos y player : %d \n", data->player_spawn_y); 
	printf("\n\n          MAP           \n");
	i = 0;
	while (data->map.tab && data->map.tab[i])
	{
		printf("%s\n", (data->map.tab[i]));
		i++;
	}
}

void	ft_print_map(t_map_data *data)
{
	int		i;
	int		j;
	char	temp;
	int		temp_i;
	int		temp_j;

	printf("\n------------------------------------\n");
	i = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (data->map && data->map[i] && data->map[i][j])
		{
			if (data->posX == j && data->posY == i)
			{
				temp_i = i;
				temp_j = j;
				temp = data->map[i][j];
				data->map[i][j] = '.';
			}
			j++;
		}
		printf("%s\n", (data->map[i]));
		i++;
	}
	data->map[temp_i][temp_j] = temp;
	printf("\n------------------------------------\n\n");

}