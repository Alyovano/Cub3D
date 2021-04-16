/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:42:58 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/13 16:45:16 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		sprite_drawing(t_bag *b, int stripe)
{
	int		y;
	int		d;

	b->pro->tex_x = (int)(256. * (stripe - (-b->pro->sprite_width / 2.
		+ b->pro->s_screen_x)) * 64. / b->pro->sprite_width) / 256.;
	if (b->pro->transform_y > 0 && stripe > 0 && stripe < b->da->x_max
		&& b->pro->transform_y < b->pro->zbuffer[stripe])
	{
		y = b->pro->start_y;
		while (y < b->pro->end_y)
		{
			d = y * 256 - b->da->y_max * 128 + b->pro->sprite_height * 128;
			b->pro->tex_y = ((d * 64.) / b->pro->sprite_height) / 256;
			b->map->color = b->da->text_i[S]
				[64 * b->pro->tex_y + b->pro->tex_x];
			if ((b->map->color & 0x00FFFFFF) != 0)
				b->map->image_i[y * b->da->x_max + stripe] = b->map->color;
			y++;
		}
	}
	return (0);
}

int		sprite_init_values(t_bag *b)
{
	b->pro->inv_det = 1.0 / (b->pro->plan_x * b->pro->dir_y - b->pro->dir_x
		* b->pro->plan_y);
	b->pro->transform_x = b->pro->inv_det
		* (b->pro->dir_y * b->pro->item_x - b->pro->dir_x * b->pro->item_y);
	b->pro->transform_y = b->pro->inv_det
	* (-b->pro->plan_y * b->pro->item_x + b->pro->plan_x * b->pro->item_y);
	b->pro->s_screen_x = (int)((b->da->x_max / 2.)
		* (1. + b->pro->transform_x / b->pro->transform_y));
	b->pro->sprite_height =
		abs((int)(b->da->y_max / (b->pro->transform_y)));
	b->pro->start_y = -b->pro->sprite_height / 2 + b->da->y_max / 2;
	if (b->pro->start_y < 0)
		b->pro->start_y = 0;
	b->pro->end_y = b->pro->sprite_height / 2 + b->da->y_max / 2;
	if (b->pro->end_y >= b->da->y_max)
		b->pro->end_y = b->da->y_max - 1;
	b->pro->sprite_width = abs((int)(b->da->y_max / (b->pro->transform_y)));
	b->pro->start_x = -b->pro->sprite_width / 2 + b->pro->s_screen_x;
	if (b->pro->start_x < 0)
		b->pro->start_x = 0;
	b->pro->end_x = b->pro->sprite_width / 2 + b->pro->s_screen_x;
	if (b->pro->end_x >= b->da->x_max)
		b->pro->end_x = b->da->x_max - 1;
	return (0);
}

int		sprite(t_bag *b)
{
	int				i;
	int				stripe;

	i = 0;
	sort_items(b);
	while (i < b->pro->nbitems)
	{
		b->pro->item_x = b->sprite[b->pro->s_order[i]].x - b->pro->pos_x;
		b->pro->item_y = b->sprite[b->pro->s_order[i]].y - b->pro->pos_y;
		sprite_init_values(b);
		stripe = b->pro->start_x;
		while (stripe < b->pro->end_x)
		{
			sprite_drawing(b, stripe);
			stripe++;
		}
		i++;
	}
	return (0);
}
