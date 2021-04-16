/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 09:40:07 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 15:24:36 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_init_parse(t_bag *b)
{
	if (!(b->map = malloc(sizeof(t_map))))
		return (ERROR);
	if (!(b->da = malloc(sizeof(t_parse))))
		return (ERROR);
	if (!(b->pro = malloc(sizeof(t_pro))))
		return (ERROR);
	ft_bzero(&b->keys, 4);
	b->map->cell_x = 0;
	b->map->cell_y = 0;
	b->map->sl = 0;
	b->map->bpp = 0;
	b->map->endi = 1;
	b->map->color = 0;
	b->map->starter = 0;
	b->map->text_starter = 0;
	b->da->x_max = -1;
	b->da->y_max = -1;
	b->da->fl[0] = 0;
	b->da->fl[1] = 0;
	b->da->fl[2] = 0;
	b->da->cl[0] = 0;
	b->da->cl[1] = 0;
	b->da->cl[2] = 0;
	b->da->tmp = NULL;
	return (0);
}

void	ft_init_prostruct(t_bag *b)
{
	b->pro->pos_x = (ft_pos_player(b, 'x') + 0.5);
	b->pro->pos_y = (ft_pos_player(b, 'y') + 0.5);
	b->pro->dir_x = 1.0;
	b->pro->dir_y = 0.0;
	b->pro->plan_x = 0.0;
	b->pro->plan_y = 0.66;
	b->pro->camera_x = 0.0;
	b->pro->raydir_x = 0.0;
	b->pro->raydir_y = 0.0;
	b->pro->map_x = 0.0;
	b->pro->map_y = 0.0;
	b->pro->side_dist_x = 0.0;
	b->pro->side_dist_y = 0.0;
	b->pro->delta_dist_x = 0.0;
	b->pro->delta_dist_y = 0.0;
	b->pro->perp_w_dist = 0.0;
	b->pro->step_x = 0;
	b->pro->step_y = 0;
	b->pro->hit = 0;
	b->pro->side = 0;
	b->pro->draw_start = 0;
	b->pro->draw_end = 0;
	b->pro->line_height = 0;
}

void	ft_init_dir(t_bag *b)
{
	int		i;

	i = 0;
	if (b->da->dir == 'N')
		b->da->dir -= 77;
	else if (b->da->dir == 'W')
		b->da->dir -= 85;
	else if (b->da->dir == 'S')
		b->da->dir -= 80;
	else
		b->da->dir = 0;
	while (i < QUARTER * b->da->dir)
	{
		move_left(b);
		i++;
	}
}

int		ft_img_bmp2(t_bag *b, int input, int *color, int fd)
{
	int		i;

	if (write(fd, &b->da->y_max, 2) != 2)
		return (ERROR);
	input = 1;
	if (write(fd, &input, 2) != 2)
		return (ERROR);
	input = 24;
	if (write(fd, &input, 2) != 2)
		return (ERROR);
	input = b->da->x_max * b->da->y_max - sizeof(int);
	while (input > 0)
	{
		color[0] = (b->map->image_i[input] >> 0 & 255);
		color[1] = (b->map->image_i[input] >> 8 & 255);
		color[2] = (b->map->image_i[input] >> 16 & 255);
		i = 0;
		while (i < 3)
		{
			if (write(fd, &color[i++], 1) != 1)
				return (ERROR);
		}
		input--;
	}
	return (close(fd));
}

int		ft_img_bmp(t_bag *b)
{
	int		fd;
	int		input;
	int		color[3];

	if ((fd = open("Cub3D.bmp", O_CREAT | O_WRONLY, 0755)) == -1)
		return (ERROR);
	input = 14 + 12 + (b->da->x_max * b->da->y_max * 3);
	if (write(fd, "BM", 2) != 2)
		return (ERROR);
	if (write(fd, &input, 4) != 4)
		return (ERROR);
	input = 0;
	if (write(fd, &input, 4) != 4)
		return (ERROR);
	input = 26;
	if (write(fd, &input, 4) != 4)
		return (ERROR);
	input = 12;
	if (write(fd, &input, 4) != 4)
		return (ERROR);
	if (write(fd, &b->da->x_max, 2) != 2)
		return (ERROR);
	return (ft_img_bmp2(b, input, color, fd));
}
