/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:15:36 by yocapell          #+#    #+#             */
/*   Updated: 2020/02/19 16:15:38 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_floor(char *tmp, t_bag *b)
{
	int		j;

	j = 0;
	b->verif->token_flo = 1;
	if ((j = skip_all_useless_info(tmp)) == ERROR)
		return (ERROR);
	tmp += j;
	b->da->fl[0] = ft_atoi(tmp);
	tmp += ft_nbrlen(b->da->fl[0]);
	if ((j = skip_all_useless_info(tmp)) == ERROR)
		return (ERROR);
	tmp += j;
	b->da->fl[1] = ft_atoi(tmp);
	tmp += ft_nbrlen(b->da->fl[1]);
	if ((j = skip_all_useless_info(tmp)) == ERROR)
		return (ERROR);
	tmp += j;
	b->da->fl[2] = ft_atoi(tmp);
	tmp += ft_nbrlen(b->da->fl[2]);
	return (0);
}

int		parse_ceiling(char *tmp, t_bag *b)
{
	int		j;

	j = 0;
	b->verif->token_cel = 1;
	if ((j = skip_all_useless_info(tmp)) == ERROR)
		return (ERROR);
	tmp += j;
	b->da->cl[0] = ft_atoi(tmp);
	tmp += ft_nbrlen(b->da->cl[0]);
	if ((j = skip_all_useless_info(tmp)) == ERROR)
		return (ERROR);
	tmp += j;
	b->da->cl[1] = ft_atoi(tmp);
	tmp += ft_nbrlen(b->da->cl[1]);
	if ((j = skip_all_useless_info(tmp)) == ERROR)
		return (ERROR);
	tmp += j;
	b->da->cl[2] = ft_atoi(tmp);
	tmp += ft_nbrlen(b->da->cl[2]);
	return (0);
}

int		parse_res(char *tmp, t_bag *b)
{
	int i;

	i = 0;
	b->verif->token_res = 1;
	if ((i = skip_all_useless_info(tmp)) == ERROR)
		return (ERROR);
	tmp += i;
	b->da->x_max = ft_atoi(tmp);
	tmp += ft_nbrlen(b->da->x_max);
	if ((i = skip_all_useless_info(tmp)) == ERROR)
		return (ERROR);
	tmp += i;
	b->da->y_max = ft_atoi(tmp);
	return (0);
}

void	catch_texture(char *str, t_bag *b)
{
	if (b->verif->token_no == 1)
	{
		b->verif->token_no = 2;
		b->da->t[NO] = ft_strdup(str + 3);
	}
	else if (b->verif->token_so == 1)
	{
		b->verif->token_so = 2;
		b->da->t[SO] = ft_strdup(str + 3);
	}
	else if (b->verif->token_we == 1)
	{
		b->verif->token_we = 2;
		b->da->t[WE] = ft_strdup(str + 3);
	}
	else if (b->verif->token_ea == 1)
	{
		b->verif->token_ea = 2;
		b->da->t[EA] = ft_strdup(str + 3);
	}
	else if (b->verif->token_sprite == 1)
	{
		b->verif->token_sprite = 2;
		b->da->s = ft_strdup(str + 2);
	}
}

int		catch_flag(char *str, t_bag *b)
{
	if (*str == 'R' && b->verif->token_res == 0)
	{
		if (parse_res(str, b) == ERROR)
			b->verif->token_res = 0;
	}
	else if (*str == 'C' && b->verif->token_cel == 0)
	{
		if (parse_ceiling(str, b) == ERROR)
			b->verif->token_cel = 0;
	}
	else if (*str == 'F' && b->verif->token_flo == 0)
	{
		if (parse_floor(str, b) == ERROR)
			b->verif->token_flo = 0;
	}
	else if (ft_isdigit(*str))
	{
		b->da->tmp = ft_strjoin_free(b->da->tmp, str);
		b->verif->token_map = 1;
		b->da->count++;
	}
	return (0);
}
