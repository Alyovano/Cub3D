/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:06:14 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/30 14:53:38 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_precision(char *s, t_struct *u)
{
	int	k;

	k = ft_treat_neg(&u->width);
	u->precision = (size_t)u->precision >= ft_strlen(s) ? ft_strlen(s)
		: (size_t)u->precision;
	if (u->flags == '0' && u->width > u->precision)
	{
		ft_precision_x_zero(u, 0);
		write(1, s, u->precision);
		u->i += u->precision;
	}
	else if (u->flags == '-' && u->width > u->precision)
	{
		write(1, s, u->precision);
		u->i += u->precision;
		ft_precision_space(u, 0);
	}
	else
		ft_s_precision2(s, u, k);
}

void	ft_s_precision2(char *s, t_struct *u, int k)
{
	if (u->width > u->precision)
	{
		k == 0 ? ft_precision_space(u, 0) : 0;
		write(1, s, u->precision);
		u->i += u->precision;
		k == 1 ? ft_precision_space(u, 0) : 0;
	}
	else
	{
		write(1, s, u->precision);
		u->i += u->precision;
	}
}

void	ft_i_precision(int i, t_struct *u)
{
	int		k;

	k = ft_treat_neg(&i);
	if (u->precision == 0 && i == 0)
		return (ft_precision_space(u, k));
	if (u->precision < (int)ft_nbrlen(i))
		u->precision = ft_nbrlen(i);
	if (u->precision != -1 && u->flags == '-')
	{
		k == 1 ? write(1, "-", 1) : 0;
		k == 1 ? u->i++ : 0;
		ft_precision_zero(u, i, 'i');
		ft_precision_space(u, k);
	}
	else
	{
		u->width > 0 ? ft_precision_space(u, k) : 0;
		k == 1 ? write(1, "-", 1) : 0;
		k == 1 ? u->i++ : 0;
		ft_precision_zero(u, i, 'i');
		u->width < 0 ? ft_precision_space(u, k) : 0;
	}
}

void	ft_u_precision(unsigned int i, t_struct *u)
{
	if (u->precision == 0 && i == 0)
		return (ft_precision_space(u, 0));
	if (u->precision >= 0)
		if (u->precision < (int)ft_nbrlen(i))
			u->precision = ft_nbrlen(i);
	if (u->precision != -1 && u->flags == '-')
	{
		ft_precision_zero(u, i, 'u');
		if (u->width > u->precision && u->precision < 0)
			ft_width_space(u, i, 0);
		else
			ft_precision_space(u, 0);
	}
	else
	{
		if (u->width > 0)
			u->width > u->precision && u->precision < 0 ? ft_width_zero(u, i, 0)
				: ft_precision_space(u, 0);
		ft_precision_zero(u, i, 'u');
		if (u->flags == '0')
			u->width < 0 && u->flags == '0' ? ft_precision_space(u, 0) : 0;
		else
			u->width < 0 ? ft_width_space(u, i, 0) : 0;
	}
}

void	ft_x_precision(t_struct *u, char c, char *x_min, char *x_max)
{
	int		k;

	k = u->precision < 0 || u->width < 0 ? 1 : 0;
	if (u->precision == 0 && ft_strncmp(x_min, "0", ft_strlen(x_min)) == 0)
		return (ft_precision_space(u, 0));
	if (u->precision < (int)ft_strlen(x_min))
		u->precision = (int)ft_strlen(x_min);
	if (u->precision != -1 && u->flags == '-')
	{
		c == 'x' ? ft_prec_x_zero(u, x_min) : ft_prec_x_zero(u, x_max);
		ft_precision_space(u, 0);
		u->width < 0 ? ft_width_x_space(u) : 0;
	}
	else
	{
		if (u->width > 0)
			u->flags == '0' && k == 1 ?
				ft_precision_x_zero(u, 0) : ft_precision_space(u, 0);
		c == 'x' ? ft_prec_x_zero(u, x_min) : ft_prec_x_zero(u, x_max);
		u->width < 0 ? ft_precision_space(u, 0) : 0;
	}
}
