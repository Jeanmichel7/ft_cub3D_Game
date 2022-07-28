/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:08:02 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_print_square_map(t_data *data, t_minimap *m, int color)
{
	int	old_x;
	int	old_y;

	old_y = m->y;
	while (old_y <= (m->y + m->step))
	{
		old_x = m->x;
		while (old_x <= (m->x + m->step))
		{
			ft_my_mlx_pixel_put(data, old_x, old_y, color);
			old_x++;
		}
		old_y++;
	}
}

int	ft_check_overflow(t_ray *ray, int value, t_minimap *m)
{
	int	i;

	i = 0;
	while (ray->map[m->j][i])
		i++;
	if (i < value)
		return (1);
	return (0);
}

void	ft_print_grind(t_data *data, t_ray *ray, t_minimap *m)
{
	while (m->j <= (int)ray->pos_y + 5 && m->j >= (int)ray->pos_y - 5)
	{
		m->x = data->resolution_y / 25;
		m->i = (int)ray->pos_x - 5;
		while (m->i <= (int)ray->pos_x + 5 && m->i >= (int)ray->pos_x - 5)
		{
			if (m->j < 0 || m->i < 0 || m->j >= m->height || m->i >= m->width
				|| ft_check_overflow(ray, m->i, m)
				|| ray->map[m->j][m->i] == '1')
				m->color = 0xD3D3D3;
			else if (ray->map[m->j][m->i] == '2')
				m->color = 0x582900;
			else if (ray->map[m->j][m->i] <= '0' || ray->map[m->j][m->i] == 'N'
				|| ray->map[m->j][m->i] == 'S' || ray->map[m->j][m->i] == 'W'
				|| ray->map[m->j][m->i] == 'E')
				m->color = 0xF0F0F2;
			ft_print_square_map(data, m, m->color);
			m->x += m->step;
			m->i++;
		}
	m->y += m->step;
	m->j++;
	}
}

void	ft_print_pos(t_data *data, t_minimap *m)
{
	int	x;
	int	y;

	x = m->middle - 3;
	y = m->middle - 3;
	while (y <= m->middle + 3)
	{
		x = m->middle - 3;
		while (x <= (m->middle + 3))
		{
			ft_my_mlx_pixel_put(data, x, y, 65280);
			x++;
		}
		y++;
	}
}

void	ft_print_minimap_render(t_data *data, t_ray *ray, t_minimap *m)
{
	ft_init_minimap(data, m, ray);
	ft_print_grind(data, ray, m);
	ft_print_pos(data, m);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->display, 0, 0);
}
