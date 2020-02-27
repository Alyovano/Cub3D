/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:15:58 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 16:16:00 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		map_output_error(char verif)
{
	if (verif == 1)
		ft_putstr_fd("The map must be surrounded by walls\n", 1);
	if (verif == 2)
	{
		ft_putstr_fd("Map can only contains : Walls (1)\n", 1);
		ft_putstr_fd("                      : Items (2)\n", 1);
		ft_putstr_fd("                      ", 1);
		ft_putstr_fd(": Player (N,S,W,E)\n", 1);
	}
	if (verif == 3)
		ft_putstr_fd("The map must be surrounded by walls\n", 1);
	if (verif == 4)
		ft_putstr_fd("Where is the player ?\n", 1);
	return (ERROR);
}

char	*ft_del_char(t_bag *b)
{
	char	*return_str;
	int		i;
	int		j;

	if (!(return_str = calloc(sizeof(char), (ft_strlen(b->da->tmp) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (b->da->tmp[i])
	{
		if (ft_isdigit(b->da->tmp[i]) || b->da->tmp[i] == 'S' ||
		b->da->tmp[i] == 'N' || b->da->tmp[i] == 'E' || b->da->tmp[i] == 'W')
		{
			return_str[j] = b->da->tmp[i];
			j++;
		}
		i++;
	}
	return_str[j] = '\0';
	free(b->da->tmp);
	return (return_str);
}

int		skip_all_useless_info(char *str)
{
	int i;

	i = 0;
	while (!ft_isdigit(str[i]))
	{
		if (str[i] == '\0')
			return (ERROR);
		i++;
	}
	return (i);
}

int		skip_white_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'R' || str[i] == 'F' || str[i] == 'C'
		|| (str[i] == 'N' && str[i + 1] == 'O')
		|| (str[i] == 'S' && str[i + 1] == 'O')
		|| (str[i] == 'S' && str[i + 1] != 'O')
		|| (str[i] == 'W' && str[i + 1] == 'E')
		|| (str[i] == 'E' && str[i + 1] == 'A')
		|| str[i] == '1' || str[i] == '0')
			return (i);
		i++;
	}
	return (ERROR);
}

int		ft_pos_player(t_bag *b, int o)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (b->da->map[i])
	{
		while (b->da->map[i][j])
		{
			if (b->da->map[i][j] == 'N' || b->da->map[i][j] == 'W'
				|| b->da->map[i][j] == 'E' || b->da->map[i][j] == 'S')
			{
				b->da->dir = b->da->map[i][j];
				if (o == 'x')
					return (j);
				else if (o == 'y')
					return (i);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (ERROR);
}
