/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:15:25 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/28 15:06:25 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

typedef struct sprite_calc
{
	int				i;
	double			sprite_x;
	double			sprite_y;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
	int				spritewidth;
	int				stripe;
	int				texx;
	int				texy;
	unsigned int	d;
	unsigned int	color;
	int				img_height;
	int				img_width;
	int				resolution_y;
	int				resolution_x;
	int				*addr;
}	t_sprite_calc;

void	ft_sort_sprite(int	*sprite_order, double *sprite_distance,
int sprites_nb)
{
	int	i;
	int	j;
	int	x;

	i = 1;
	while (i < sprites_nb)
	{
		x = sprite_order[i];
		j = i;
		while (j > 0 && (sprite_distance[x]
				> sprite_distance[sprite_order[j - 1]]))
		{	
			sprite_order[j] = sprite_order[j - 1];
			j = j - 1;
		}
		sprite_order[j] = x;
		i++;
	}
}

void	ft_calc_pos(t_sprite *sprite, t_sprite_calc *sp, t_ray *ray,
t_data *data)
{
	sp->sprite_x = sprite[data->sprite_order[sp->i]].x - ray->pos_x ;
	sp->sprite_y = sprite[data->sprite_order[sp->i]].y - ray->pos_y ;
	sp->invdet = 1 / (ray->plane_x * ray->dir_y - ray-> dir_x * ray->plane_y);
	sp->transformx = sp->invdet * (ray->dir_y * sp->sprite_x
			- ray->dir_x * sp->sprite_y);
	sp->transformy = sp->invdet * (-ray->plane_y * sp->sprite_x
			+ ray->plane_x * sp->sprite_y);
	sp->spritescreenx = (int)((data->resolution_x / 2)
			* (1 + sp->transformx / sp->transformy));
	sp->spriteheight = abs((int)(data->resolution_y / (sp->transformy)));
	sp->drawstarty = -sp->spriteheight / 2 + data->resolution_y / 2;
	if (sp->drawstarty < 0)
		sp->drawstarty = 0;
	sp->drawendy = sp->spriteheight / 2 + data->resolution_y / 2;
	if (sp->drawendy >= data->resolution_y)
		sp->drawendy = data->resolution_y - 1;
	sp->spritewidth = abs((int)(data->resolution_y / (sp->transformy)));
	sp->drawstartx = -sp->spritewidth / 2 + sp->spritescreenx ;
	if (sp->drawstartx < 0)
		sp->drawstartx = 0;
	sp->drawendx = sp->spritewidth / 2 + sp->spritescreenx;
	if (sp->drawendx >= data->resolution_x)
		sp->drawendx = data->resolution_x;
	sp->stripe = sp->drawstartx;
}

void	ft_print_sprite(t_sprite_calc *sp, t_data *data)
{
	int	y;

	while (sp->stripe < sp->drawendx)
	{
		sp->texx = (int)(256 * (sp->stripe - (-sp->spritewidth / 2
						+ sp->spritescreenx))
				* sp->img_width / sp->spritewidth) / 256;
		y = sp->drawstarty;
		if (sp->transformy > 0 && sp->stripe >= 0
			&& sp->stripe < data->resolution_x
			&& sp->transformy < data->zbuffer[sp->stripe])
		{
			while (y < sp->drawendy)
			{
				sp->d = y * 256 - sp->resolution_y
					* 128 + sp->spriteheight * 128;
				sp->texy = ((sp->d * sp->img_height) / sp->spriteheight) / 256;
				sp->color = sp->addr[sp->img_width * sp->texy + sp->texx];
				if (sp->color > 0x0 && sp->color < 2147483647)
					ft_my_mlx_pixel_put(data, sp->stripe, y, sp->color);
				++y;
			}
		}
		sp->stripe++;
	}
}

void	ft_init_print_sprite(t_data *data, t_ray *ray,
	t_sprite *sprite, t_sprite_calc *sp)
{
	int	order;

	order = data->sprite_order[sp->i];
	sp->img_height = data->texture[sprite[order].select_sprite].img_height;
	sp->img_width = data->texture[sprite[order].select_sprite].img_width;
	sp->addr = data->texture[sprite[order].select_sprite].addr;
	sp->resolution_y = data->resolution_y;
	sp->resolution_x = data->resolution_x;
	ft_calc_pos(sprite, sp, ray, data);
	ft_print_sprite(sp, data);
	sp->i++;
}

void	ft_sprite_casting(t_data *data, t_ray *ray, t_sprite *sprite)
{
	t_sprite_calc	sp;

	sprite = data->sprite;
	sp.i = 0;
	while (sp.i < data->sprites_nb)
	{
		data->sprite_order[sp.i] = sp.i;
		data->sprite_distance[sp.i] = ((ray->pos_x - sprite[sp.i].x) \
		* (ray->pos_x - sprite[sp.i].x) + (ray->pos_y - sprite[sp.i].y) \
		* (ray->pos_y - sprite[sp.i].y));
		sp.i++;
	}
	ft_sort_sprite(data->sprite_order, data->sprite_distance, data->sprites_nb);
	sp.i = 0;
	while (sp.i < data->sprites_nb)
		ft_init_print_sprite(data, ray, sprite, &sp);
}
