/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:18:56 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/16 17:59:16 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_wall_coloring(t_bag *b, unsigned int y, unsigned int n)
{
	unsigned int	tex_y;
	unsigned int	tex_x;
	unsigned int	pix;

	tex_y = ((float)y / (float)b->pro->line_height) * 64.;
	if (b->pro->side == 0)
		tex_x = abs(64 - (int)(b->pro->wall_x * 64.) - 1);
	else
		tex_x = abs(64 - (int)(b->pro->wall_x * 64.) - 1);
	pix = tex_x + tex_y * 64;
	if ((n + b->map->starter) < (unsigned int)(b->da->res_max) &&
	b->pro->map_y < b->pro->pos_y && b->pro->side == 1 && pix < 4096)
		b->map->image_i[n + (int)b->map->starter] = b->da->text_i[NO][pix];
	else if ((n + b->map->starter) < (unsigned int)(b->da->res_max) &&
		b->pro->map_x < b->pro->pos_x && b->pro->side == 0 && pix < 4096)
		b->map->image_i[n + (int)b->map->starter] = b->da->text_i[WE][pix];
	else if ((n + b->map->starter) < (unsigned int)(b->da->res_max) &&
		b->pro->map_x && b->pro->side == 1 && pix < 4096)
		b->map->image_i[n + (int)b->map->starter] = b->da->text_i[SO][pix];
	else if ((n + b->map->starter) < (unsigned int)(b->da->res_max) &&
		b->pro->map_y && b->pro->side == 0 && pix < 4096)
		b->map->image_i[n + (int)b->map->starter] = b->da->text_i[EA][pix];
	return (0);
}

int				ft_wall_drawing(t_bag *b)
{
	unsigned int	n;
	unsigned int	y;

	y = 0;
	b->pro->line_height = (int)(b->da->y_max / b->pro->perp_w_dist);
	b->pro->line_height = b->pro->line_height;
	n = ((b->da->res_max) * 0.5) - ((b->pro->line_height / 2) * b->da->x_max);
	if (b->map->starter >= b->da->x_max)
		b->map->starter = 0;
	b->pro->wall_x = b->pro->side == 0 ? b->pro->pos_y + b->pro->perp_w_dist
	* b->pro->raydir_y : b->pro->pos_x + b->pro->perp_w_dist * b->pro->raydir_x;
	b->pro->wall_x -= floor((b->pro->wall_x));
	while (y < (unsigned int)b->pro->line_height)
	{
		ft_wall_coloring(b, y, n);
		n += b->da->x_max;
		y++;
	}
	++b->map->starter;
	return (0);
}

void			ft_hit(t_bag *b, int i)
{
	while (b->pro->hit == 0)
	{
		if (b->pro->side_dist_x < b->pro->side_dist_y)
		{
			b->pro->side_dist_x += b->pro->delta_dist_x;
			b->pro->map_x += b->pro->step_x;
			b->pro->side = 0;
		}
		else
		{
			b->pro->side_dist_y += b->pro->delta_dist_y;
			b->pro->map_y += b->pro->step_y;
			b->pro->side = 1;
		}
		if (b->da->map[(int)b->pro->map_y][(int)b->pro->map_x] == '1')
			b->pro->hit = 1;
	}
	if (b->pro->side == 0)
		b->pro->perp_w_dist = (b->pro->map_x - b->pro->pos_x +
			(double)(1 - b->pro->step_x) * 0.5) / b->pro->raydir_x;
	else
		b->pro->perp_w_dist = (b->pro->map_y - b->pro->pos_y +
			(double)(1 - b->pro->step_y) * 0.5) / b->pro->raydir_y;
	b->pro->zbuffer[i] = b->pro->perp_w_dist;
	ft_wall_drawing(b);
}

void			ft_dist_side(t_bag *b, int i)
{
	if (b->pro->raydir_x < 0.0)
	{
		b->pro->step_x = -1;
		b->pro->side_dist_x = (b->pro->pos_x - b->pro->map_x)
		* b->pro->delta_dist_x;
	}
	else
	{
		b->pro->step_x = 1;
		b->pro->side_dist_x = (b->pro->map_x + 1.0 - b->pro->pos_x)
		* b->pro->delta_dist_x;
	}
	if (b->pro->raydir_y < 0.0)
	{
		b->pro->step_y = -1;
		b->pro->side_dist_y = (b->pro->pos_y - b->pro->map_y)
		* b->pro->delta_dist_y;
	}
	else
	{
		b->pro->step_y = 1;
		b->pro->side_dist_y = (b->pro->map_y + 1.0 - b->pro->pos_y)
		* b->pro->delta_dist_y;
	}
	ft_hit(b, i);
}

void			ft_raycasting(t_bag *b)
{
	int		i;
	int		w;

	ft_color_background(b);
	i = -1;
	w = b->da->x_max;
	while (++i < w)
	{
		b->pro->camera_x = 2.0 * i / (double)w - 1;
		b->pro->raydir_x = b->pro->dir_x + (b->pro->plan_x * b->pro->camera_x);
		b->pro->raydir_y = b->pro->dir_y + (b->pro->plan_y * b->pro->camera_x);
		b->pro->map_x = (int)b->pro->pos_x;
		b->pro->map_y = (int)b->pro->pos_y;
		b->pro->delta_dist_x = (double)fabs(1.0 / b->pro->raydir_x);
		b->pro->delta_dist_y = (double)fabs(1.0 / b->pro->raydir_y);
		b->pro->hit = 0;
		ft_dist_side(b, i);
	}
}
