/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:13:58 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 16:14:02 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		first_free(t_bag *b)
{
	mlx_destroy_window(b->map->mlx_ptr, b->map->win_ptr);
	return (destroy_and_free(b));
}

int		second_free(t_bag *b, char verif)
{
	if (verif >= 1)
		mlx_destroy_image(b->map->mlx_ptr, b->map->image);
	if (verif >= 2)
		free(b->sprite);
	if (verif >= 3)
		free(b->pro->zbuffer);
	if (verif >= 4)
		free(b->pro->s_distance);
	if (verif >= 5)
		free(b->pro->s_order);
	return (first_free(b));
}
