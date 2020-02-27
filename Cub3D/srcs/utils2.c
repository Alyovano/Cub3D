/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:24:20 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 14:58:10 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_init_textures(t_bag *b)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (!(b->da->textures[i] = mlx_png_file_to_image(b->map->mlx_ptr,
				b->da->t[i], &b->da->w_text, &b->da->h_text)))
		{
			while (--i > 0)
				mlx_destroy_image(b->map->mlx_ptr, b->da->textures[i]);
			return (ERROR);
		}
		b->da->text_i[i] = (int *)mlx_get_data_addr(b->da->textures[i],
			&b->map->bpp, &b->map->sl, &b->map->endi);
		i++;
	}
	if (!(b->da->textures[S] = mlx_png_file_to_image(b->map->mlx_ptr,
			b->da->s, &b->da->w_text, &b->da->h_text)))
	{
		mlx_destroy_image(b->map->mlx_ptr, b->da->textures[S]);
		return (ERROR);
	}
	b->da->text_i[S] = (int *)mlx_get_data_addr(b->da->textures[S],
		&b->map->bpp, &b->map->sl, &b->map->endi);
	return (0);
}

int		ft_item_nb(t_bag *b)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (b->da->map[i])
	{
		j = 0;
		while (b->da->map[i][j])
		{
			if (b->da->map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		ft_pos_item(t_bag *b)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (b->da->map[i])
	{
		while (b->da->map[i][j])
		{
			if (b->da->map[i][j] == '2')
			{
				b->sprite[k].x = j + 0.5;
				b->sprite[k].y = i + 0.5;
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		sort_items2(t_bag *b, int end, int finished, int changed)
{
	int		i;

	i = 0;
	while (!finished)
	{
		i = 0;
		changed = 0;
		while (i < end)
		{
			if (b->pro->s_distance[i] < b->pro->s_distance[i + 1])
			{
				ft_fswap(&b->pro->s_distance[i], &b->pro->s_distance[i + 1]);
				ft_swap(&b->pro->s_order[i], &b->pro->s_order[i + 1]);
				changed = 1;
			}
			i++;
		}
		if (changed)
			end--;
		else
			finished = 1;
	}
	return (0);
}

int		sort_items(t_bag *b)
{
	int		i;
	int		end;
	char	finished;
	char	changed;

	i = 0;
	end = b->pro->nbitems - 1;
	finished = 0;
	changed = 0;
	while (i < b->pro->nbitems)
	{
		b->pro->s_order[i] = i;
		b->pro->s_distance[i] = ((b->pro->pos_x - (double)b->sprite[i].x) *
		(b->pro->pos_x - (double)b->sprite[i].x) + (b->pro->pos_y -
		(double)b->sprite[i].y) * (b->pro->pos_y - (double)b->sprite[i].y));
		i++;
	}
	return (sort_items2(b, end, finished, changed));
}
