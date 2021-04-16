/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:21:25 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 15:37:50 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		scan_tmp_map(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			return (1);
		i++;
	}
	return (ERROR);
}

int		ft_cat_int(int one, int two, int three)
{
	one *= 0x10000;
	two *= 0x100;
	three *= 0x1;
	one += two + three;
	return (one);
}

int		ft_final_init(t_bag *b)
{
	b->da->res_max = b->da->y_max * b->da->x_max;
	if (!(b->map->image = mlx_new_image(b->map->mlx_ptr,
		b->da->x_max, b->da->y_max)))
		return (second_free(b, 1));
	b->map->image_i = (int *)mlx_get_data_addr(b->map->image, &b->map->bpp,
		&b->map->sl, &b->map->endi);
	b->pro->nbitems = ft_item_nb(b);
	if (!(b->sprite = malloc(sizeof(t_sprite) * (b->pro->nbitems + 1))))
		return (second_free(b, 2));
	ft_pos_item(b);
	if (!(b->pro->zbuffer = malloc(sizeof(double) * (b->da->x_max + 1))))
		return (second_free(b, 3));
	if (!(b->pro->s_distance = malloc(sizeof(double) * (b->pro->nbitems + 1))))
		return (second_free(b, 4));
	if (!(b->pro->s_order = malloc(sizeof(int) * (b->pro->nbitems + 1))))
		return (second_free(b, 5));
	ft_init_dir(b);
	return (0);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*ret_str;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		s1 ? free((char*)s1) : 0;
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	}
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!(ret_str = (char *)malloc(s1_size + s2_size + 1 * sizeof(char))))
		return (NULL);
	ft_memcpy(ret_str, s1, s1_size);
	ft_memcpy(ret_str + s1_size, s2, s2_size + 1);
	free((char*)s1);
	return (ret_str);
}
