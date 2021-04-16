/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_parse2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:15:50 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 16:15:51 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			map_verif_while(t_bag *b, unsigned int i,
								unsigned int j, unsigned int size)
{
	j = 1;
	if (b->da->map[i][size] != '1' || b->da->map[i][0] != '1')
		return (map_output_error(1));
	else
	{
		while (b->da->map[i][j])
		{
			if (b->da->map[i][j] != 'N' && b->da->map[i][j] != 'S'
			&& b->da->map[i][j] != 'W' && b->da->map[i][j] != 'E'
			&& b->da->map[i][j] != '1' && b->da->map[i][j] != '0'
			&& b->da->map[i][j] != '2')
				return (map_output_error(2));
			if (b->da->map[i][j] == 'N' || b->da->map[i][j] == 'S'
			|| b->da->map[i][j] == 'W' || b->da->map[i][j] == 'E')
				b->verif->token_player++;
			j++;
		}
	}
	return (0);
}

int			map_verification(t_bag *b)
{
	unsigned int i;
	unsigned int j;
	unsigned int size;

	i = 0;
	j = 0;
	size = (ft_strlen(b->da->map[0]) - 1);
	while (b->da->map[i])
	{
		if (i == 0 || i == b->da->count - 1)
		{
			j = 0;
			while (b->da->map[i][j])
			{
				if (b->da->map[i][j] != '1')
					return (map_output_error(3));
				j++;
			}
		}
		else
			map_verif_while(b, i, j, size);
		i++;
	}
	return (b->verif->token_player != 1 ? map_output_error(4) : 0);
}

int			ft_map_to_tab(t_bag *b)
{
	unsigned int	value;
	unsigned int	i;

	value = 0;
	i = 0;
	if (!(b->da->map = malloc(sizeof(char*) * (b->da->count + 1))))
		return (ERROR);
	b->da->tmp = ft_del_char(b);
	value = ft_strlen(b->da->tmp) / b->da->count;
	if (ft_strlen(b->da->tmp) % b->da->count != 0)
	{
		if (scan_tmp_map(b->da->tmp) == ERROR)
			ft_putstr_fd("Need player letter - > (N.E.W.S)\n", 1);
		else
			ft_putstr_fd("The map can only have 4 sides\n", 1);
		return (ERROR);
	}
	while (i < b->da->count)
	{
		b->da->map[i++] = ft_strndup(b->da->tmp, value);
		b->da->tmp += value;
	}
	b->da->map[b->da->count] = 0;
	return (0);
}

int			point_cub(char *str)
{
	unsigned int	len;
	int				check;

	len = ft_strlen(str);
	check = 0;
	if (!(str[len - 1] == 'b' && str[len - 2] == 'u'
	&& str[len - 3] == 'c' && str[len - 4] == '.'))
	{
		ft_putstr_fd("Your map needs extention .cub\n", 1);
		return (ERROR);
	}
	else
	{
		ft_putstr_fd("Format \".cub\"... >OK\n", 1);
		return (1);
	}
}
