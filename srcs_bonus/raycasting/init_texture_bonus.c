/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:18:52 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:09:46 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_cpy_texture(t_data *data, t_texture **new_texture)
{
	int	i;

	*new_texture = malloc(sizeof(t_texture) * (data->textures_nb + 1));
	i = 0;
	while (i < data->textures_nb - 1)
	{
		(*new_texture)[i].path = malloc(sizeof(char) \
		* (ft_strlen(data->texture[i].path) + 1));
		ft_strlcpy((*new_texture)[i].path, data->texture[i].path,
			ft_strlen(data->texture[i].path) + 1);
		data->texture[i].is_copy += 1;
		if (data->texture[i].path && (data->texture[i].is_copy > 1 \
		|| ft_is_not_sprite(data, i)))
			free(data->texture[i].path);
		ft_sub_cpy_old_texture(data, new_texture, i);
		i++;
	}
	free(data->texture);
}

void	ft_fill_new_texture(t_data *data, t_texture **new_texture, char c)
{
	if (c == 'B')
		(*new_texture)[data->textures_nb - 1].path = "./sprites/barrel.xpm";
	(*new_texture)[data->textures_nb - 1].mlx_img = NULL;
	(*new_texture)[data->textures_nb - 1].addr = NULL;
	(*new_texture)[data->textures_nb - 1].img_width = 0;
	(*new_texture)[data->textures_nb - 1].img_height = 0;
	(*new_texture)[data->textures_nb - 1].lenght = 0;
	(*new_texture)[data->textures_nb - 1].bit_per_pixel = 0;
	(*new_texture)[data->textures_nb - 1].endian = 0;
	(*new_texture)[data->textures_nb - 1].use_color = 0;
	(*new_texture)[data->textures_nb - 1].type = c;
	(*new_texture)[data->textures_nb - 1].is_copy = 0;
}

void	ft_add_texture(t_data *data, int x, int y, int *j)
{
	t_texture	*new_texture;
	char		c;

	data->textures_nb += 1;
	new_texture = NULL;
	ft_cpy_texture(data, &new_texture);
	c = data->map.tab[y][x];
	ft_fill_new_texture(data, &new_texture, c);
	data->sprites_nb += 1;
	data->sprite[*j].x = x + 0.5;
	data->sprite[*j].y = y + 0.5;
	data->sprite[*j].texture[0] = data->textures_nb - 1;
	data->sprite[*j].texture[1] = -1;
	data->sprite[*j].select_sprite = 0;
	data->sprite[*j].is_anim = 0;
	*j += 1;
	data->texture = new_texture;
}

void	ft_init_texture(t_data *data)
{
	int	x;

	data->textures_nb = 8;
	data->sprites_nb = 0;
	data->texture = malloc(sizeof(t_texture) * data->textures_nb);
	x = 0;
	while (x < data->textures_nb)
	{
		data->texture[x].path = NULL;
		data->texture[x].mlx_img = NULL;
		data->texture[x].addr = NULL;
		data->texture[x].img_width = 0;
		data->texture[x].img_height = 0;
		data->texture[x].lenght = 0;
		data->texture[x].bit_per_pixel = 0;
		data->texture[x].endian = 0;
		data->texture[x].type = 0;
		data->texture[x].is_copy = 0;
		if (x == TEXTURE_FLOOR || x == TEXTURE_CEIL)
			data->texture[x].use_color = 1;
		else
			data->texture[x].use_color = 0;
		x++;
	}
}

int	ft_init_text(t_data *data)
{
	int			x;
	t_texture	*text;

	x = 0;
	text = data->texture;
	while (x < data->textures_nb)
	{
		if (!(text[x].use_color))
		{
			text[x].mlx_img = mlx_xpm_file_to_image(data->mlx, \
				text[x].path, &text[x].img_width, &text[x].img_height);
			if (text[x].mlx_img == NULL)
			{
				printf("Error\nTexture %d not found: %s\n", x, text[x].path);
				exit(0);
			}
			text[x].addr = (int *)mlx_get_data_addr(text[x].mlx_img, \
				&text[x].bit_per_pixel, &text[x].lenght, &text[x].endian);
		}
		x++;
	}
	return (0);
}
