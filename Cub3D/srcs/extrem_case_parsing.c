/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrem_case_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:14:10 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 16:18:19 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_max_value(t_bag *b)
{
	int token;

	token = 0;
	if (!(b->da->x_max <= 2560 && b->da->x_max > -1))
	{
		b->da->x_max = 2560;
		token = 2;
		ft_putstr_fd("Adapt res height.\n", 1);
	}
	if (!(b->da->y_max <= 1440 && b->da->y_max > -1))
	{
		b->da->y_max = 1440;
		token = 1;
		ft_putstr_fd("Adapt res width.\n", 1);
	}
	token != 0 ? ft_putstr_fd("Resize game screen.\n", 1) : 0;
	return (token);
}

int		rgb_max_value(t_bag *b)
{
	b->verif->token_cel = 1;
	b->verif->token_flo = 1;
	if (b->da->cl[0] > 255 || b->da->cl[1] > 255 || b->da->cl[2] > 255
		|| b->da->fl[0] > 255 || b->da->fl[1] > 255 || b->da->fl[2] > 255)
	{
		ft_putstr_fd("RGB colors must be between 0 and 255\n", 1);
		ft_putstr_fd("-->Cub is starting with default colors...\n", 1);
		b->da->cl[0] = 100;
		b->da->cl[1] = 100;
		b->da->cl[2] = 100;
		b->da->fl[0] = 100;
		b->da->fl[1] = 100;
		b->da->fl[2] = 100;
	}
	return (0);
}
