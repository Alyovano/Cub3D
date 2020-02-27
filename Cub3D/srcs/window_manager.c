/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:06:35 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 15:14:16 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		close_key(t_bag *b)
{
	second_free(b, 5);
	exit(0);
}

int		ft_expose(t_bag *b)
{
	b->keys.top == 0 ? 0 : move_up(b);
	b->keys.bot == 0 ? 0 : move_back(b);
	b->keys.left == 0 ? 0 : move_left(b);
	b->keys.right == 0 ? 0 : move_right(b);
	mlx_clear_window(b->map->mlx_ptr, b->map->win_ptr);
	ft_raycasting(b);
	sprite(b);
	mlx_put_image_to_window(b->map->mlx_ptr, b->map->win_ptr, b->map->image,
		0, 0);
	return (0);
}

int		key_press(int key, t_bag *b)
{
	key == ESC_KEY ? ft_putstrlen_fd("Exit Cub3D\n", 1) && close_key(b) : 0;
	if (key == W_KEY || key == UP_KEY)
		b->keys.top = 1;
	if (key == S_KEY || key == DOWN_KEY)
		b->keys.bot = 1;
	if (key == A_KEY || key == LEFT_KEY)
		b->keys.left = 1;
	if (key == D_KEY || key == RIGHT_KEY)
		b->keys.right = 1;
	return (0);
}

int		key_release(int key, t_bag *b)
{
	if (key == W_KEY || key == UP_KEY)
		b->keys.top = 0;
	if (key == S_KEY || key == DOWN_KEY)
		b->keys.bot = 0;
	if (key == A_KEY || key == LEFT_KEY)
		b->keys.left = 0;
	if (key == D_KEY || key == RIGHT_KEY)
		b->keys.right = 0;
	return (0);
}

int		mlx_starter(t_bag *b, char token)
{
	if (!(b->map->mlx_ptr = mlx_init())
	|| !(b->map->win_ptr = mlx_new_window(b->map->mlx_ptr,
		b->da->x_max, b->da->y_max, "Cub3D")))
		return (first_free(b));
	if (ft_init_textures(b) == ERROR)
		return (first_free(b));
	ft_final_init(b);
	ft_raycasting(b);
	sprite(b);
	token == 1 ? ft_img_bmp(b) == 0 && close_key(b) : 0;
	mlx_put_image_to_window(b->map->mlx_ptr, b->map->win_ptr, b->map->image,
		0, 0);
	b->map->cell_x = b->da->x_max / (ft_strlen(b->da->map[0]) * 6);
	b->map->cell_y = b->da->y_max / (b->da->count * 6);
	mlx_hook(b->map->win_ptr, KP, (1L << 0), key_press, b);
	mlx_hook(b->map->win_ptr, KEYRELEASE, (1L << 1), key_release, b);
	mlx_hook(b->map->win_ptr, DESTROYNOTIFY, 0L, close_key, b);
	mlx_loop_hook(b->map->mlx_ptr, ft_expose, b);
	mlx_loop(b->map->mlx_ptr);
	return (0);
}
