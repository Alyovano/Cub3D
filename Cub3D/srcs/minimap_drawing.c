/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_drawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:14:52 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 16:14:54 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_check_up_map(char cell)
{
	if (cell == '0')
		return (0xf5f5dc);
	else if (cell == '1')
		return (0x8b4513);
	else if (cell == '2')
		return (0x4876ff);
	else if (cell == 'N')
		return (0xcd0000);
	else if (cell == 'S')
		return (0xcd0000);
	else if (cell == 'W')
		return (0xcd0000);
	else if (cell == 'E')
		return (0xcd0000);
	else
		return (0);
}

void			*draw_cell(t_bag *b)
{
	void			*pic;
	int				*pic_i;
	unsigned int	i;

	if (!(pic = mlx_new_image(b->map->mlx_ptr, b->map->cell_x, b->map->cell_y)))
		return (NULL);
	pic_i = (int *)mlx_get_data_addr(pic, &b->map->bpp,
		&b->map->sl, &b->map->endi);
	i = 0;
	while (i < (b->map->cell_x * b->map->cell_y))
		pic_i[i++] = b->map->color;
	return (pic);
}

int				minimap_drawing(t_bag *b)
{
	int		i;
	int		j;
	int		wid;
	int		hei;

	i = 0;
	wid = b->da->x_max - (ft_strlen(b->da->map[0]) * b->map->cell_x);
	hei = b->da->y_max - (b->da->count * b->map->cell_y);
	while (b->da->map[i])
	{
		j = 0;
		while (b->da->map[i][j])
		{
			if ((b->map->color = ft_check_up_map(b->da->map[i][j])))
				mlx_put_image_to_window(b->map->mlx_ptr, b->map->win_ptr,
												draw_cell(b), wid, hei);
			j++;
			wid += b->map->cell_x;
		}
		i++;
		hei += b->map->cell_y;
		wid = b->da->x_max - (ft_strlen(b->da->map[0]) * b->map->cell_x);
	}
	return (0);
}
