/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:02:29 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/16 22:49:34 by jrasser          ###   ########.fr       */
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

void	ft_print_logo(t_map_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		printf("\u2B1B");
	else if (data->map[i][j] == '0')
		printf("\u2B1C");
	else if (data->map[i][j] == ' ')
		printf("  ");
	else if (data->map[i][j] == '.')
		printf("\u2B55");
	else if (data->map[i][j] == 'N' || data->map[i][j] == 'S' \
	|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
		printf("\u2B50");
	else
		printf("%c", (data->map[i][j]));
}

void	ft_print_map(t_map_data *data)
{
	int		i;
	int		j;
	char	temp;
	int		temp_i;
	int		temp_j;

	i = -1;
	while (data->map && data->map[++i])
	{
		j = -1;
		while (data->map && data->map[i] && data->map[i][++j])
		{
			if (data->posX == j && data->posY == i)
			{
				temp_i = i;
				temp_j = j;
				temp = data->map[i][j];
				data->map[i][j] = '.';
			}
			ft_print_logo(data, i, j);
		}
		printf("\n");
	}
	data->map[temp_i][temp_j] = temp;
	printf("nb pass start : %d\n", data->nb_pass);
}
