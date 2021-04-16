/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:14:35 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 16:14:38 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			move_up(t_bag *b)
{
	if (b->da->map[(int)(b->pro->pos_y)]
	[(int)(b->pro->pos_x + b->pro->dir_x * (1 * VITESSE * 8))] != '1')
	{
		b->pro->pos_x += b->pro->dir_x * VITESSE;
	}
	if (b->da->map[(int)(b->pro->pos_y + b->pro->dir_y * (1 * VITESSE * 8))]
	[(int)(b->pro->pos_x)] != '1')
	{
		b->pro->pos_y += b->pro->dir_y * VITESSE;
	}
	return (1);
}

int			move_back(t_bag *b)
{
	if (b->da->map[(int)(b->pro->pos_y)]
	[(int)(b->pro->pos_x - b->pro->dir_x * (1 * VITESSE * 8))] != '1')
	{
		b->pro->pos_x -= b->pro->dir_x * VITESSE;
	}
	if (b->da->map[(int)(b->pro->pos_y - b->pro->dir_y * (1 * VITESSE * 8))]
	[(int)(b->pro->pos_x)] != '1')
	{
		b->pro->pos_y -= b->pro->dir_y * VITESSE;
	}
	return (2);
}

int			move_left(t_bag *b)
{
	b->pro->olddir_x = b->pro->dir_x;
	b->pro->dir_x = b->pro->dir_x * cos(-ANGLE)
	- b->pro->dir_y * sin(-ANGLE);
	b->pro->dir_y = b->pro->olddir_x * sin(-ANGLE) + b->pro->dir_y
	* cos(-ANGLE);
	b->pro->oldplan_x = b->pro->plan_x;
	b->pro->plan_x = b->pro->plan_x * cos(-ANGLE)
	- b->pro->plan_y * sin(-ANGLE);
	b->pro->plan_y = b->pro->oldplan_x * sin(-ANGLE) + b->pro->plan_y
	* cos(-ANGLE);
	return (3);
}

int			move_right(t_bag *b)
{
	b->pro->olddir_x = b->pro->dir_x;
	b->pro->dir_x = b->pro->dir_x * cos(ANGLE) - b->pro->dir_y * sin(ANGLE);
	b->pro->dir_y = b->pro->olddir_x * sin(ANGLE) + b->pro->dir_y
	* cos(ANGLE);
	b->pro->oldplan_x = b->pro->plan_x;
	b->pro->plan_x = b->pro->plan_x * cos(ANGLE)
	- b->pro->plan_y * sin(ANGLE);
	b->pro->plan_y = b->pro->oldplan_x * sin(ANGLE) + b->pro->plan_y
	* cos(ANGLE);
	return (4);
}
