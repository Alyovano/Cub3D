/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:23:00 by yocapell          #+#    #+#             */
/*   Updated: 2019/12/10 08:29:37 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d_func(int i, t_struct *u)
{
	char	*d;

	if (u->precision > -1)
		ft_i_precision(i, u);
	else if (u->width)
		ft_width_i_manager(i, u);
	else
	{
		if (!(d = ft_itoa(i)))
			return (0);
		u->i += ft_putstrlen_fd(d, 1);
		free(d);
	}
	return (1);
}

int		ft_u_func(unsigned int i, t_struct *u)
{
	char	*u_str;

	if (u->precision != -1)
		ft_u_precision(i, u);
	else if (u->width)
		ft_width_u_manager(i, u);
	else
	{
		if (!(u_str = ft_uitoa(i)))
			return (0);
		u->i += ft_putstrlen_fd(u_str, 1);
		free(u_str);
	}
	return (1);
}

int		ft_x_func(unsigned int i, char c, t_struct *u)
{
	char	*hex_min;
	char	*hex_max;

	if (!(hex_min = ft_uitohextoa(i, "0123456789abcdef")))
		return (0);
	if (!(hex_max = ft_uitohextoa(i, "0123456789ABCDEF")))
		return (0);
	if (u->precision != -1)
		ft_x_precision(u, c, hex_min, hex_max);
	else if (u->width)
		ft_width_x_manager(u, c, hex_min, hex_max);
	else
		u->i += c == 'x' ? ft_putstrlen_fd(hex_min, 1) :
			ft_putstrlen_fd(hex_max, 1);
	free(hex_min);
	free(hex_max);
	return (1);
}

int		ft_p_func(size_t i, t_struct *u)
{
	char	*hex;

	if (!(hex = ft_uitohextoa(i, "0123456789abcdef")))
		return (0);
	if (u->precision != -1)
		ft_p_precision(u, hex);
	else if (u->width)
		ft_width_p_manager(u, hex);
	else
	{
		u->i += ft_putstrlen_fd("0x", 1);
		u->i += ft_putstrlen_fd(hex, 1);
	}
	free(hex);
	return (1);
}

int		ft_treat_neg(int *i)
{
	int		j;

	j = *i;
	*i *= *i < 0 ? -1 : 1;
	return (j < 0 ? 1 : 0);
}
