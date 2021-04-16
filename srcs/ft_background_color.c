/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:14:20 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 16:14:21 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Ajout de la couleur de fond
*/

int				ft_color_background(t_bag *b)
{
	int			i;

	i = 0;
	b->map->starter = 0;
	b->map->text_starter = 0;
	while (i < ((b->da->x_max * b->da->y_max) / 2))
	{
		b->map->image_i[i] = ft_cat_int(b->da->cl[0], b->da->cl[1],
			b->da->cl[2]);
		i++;
	}
	while (i < ((b->da->x_max * b->da->y_max)))
	{
		b->map->image_i[i] = ft_cat_int(b->da->fl[0], b->da->fl[1],
			b->da->fl[2]);
		i++;
	}
	return (0);
}
