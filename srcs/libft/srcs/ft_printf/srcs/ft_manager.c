/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:22:35 by yocapell          #+#    #+#             */
/*   Updated: 2019/12/10 08:55:05 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_struct	*ft_init_struct(t_struct *u)
{
	u->flags = '\0';
	u->width = 0;
	u->precision = -1;
	return (u);
}

void		ft_flags(char **format, t_struct *u)
{
	while (**format == '0' || **format == '-')
		*(*format)++ == '-' ? u->flags = '-' : 0;
	u->flags != '-' ? u->flags = '0' : 0;
}

void		ft_width(char **format, t_struct *u, va_list ap)
{
	if (ft_isdigit((int)**format))
	{
		u->width += ft_atoi(*format);
		while (ft_isdigit((int)**format) == 1)
			(*format)++;
	}
	else if (**format == '*')
	{
		u->width += va_arg(ap, int);
		if (u->width < 0)
		{
			u->flags = '-';
			u->width *= -1;
		}
		(*format)++;
	}
}

void		ft_precision(char **format, t_struct *u, va_list ap)
{
	(*format)++;
	if (ft_isdigit((int)**format))
	{
		u->precision += ft_atoi(*format) + 1;
		while (ft_isdigit((int)**format) == 1)
			(*format)++;
	}
	else if (**format == '*')
	{
		u->precision += va_arg(ap, int) + 1;
		(*format)++;
	}
	else
		u->precision = 0;
}

int			ft_manager(char **format, t_struct *u, va_list ap)
{
	if (**format == '0' || **format == '-')
		ft_flags(format, u);
	ft_width(format, u, ap);
	if (**format == '.')
		ft_precision(format, u, ap);
	if (ft_is_printf_specifier(**format))
	{
		**format == '%' ? ft_pc_func('%', u) : 0;
		**format == 'c' ? ft_c_func(va_arg(ap, int), u) : 0;
		**format == 's' ? ft_s_func(va_arg(ap, char*), u) : 0;
		if (**format == 'p')
			if (!(ft_p_func(va_arg(ap, size_t), u)))
				return (0);
		if (**format == 'i' || **format == 'd')
			if (!(ft_d_func(va_arg(ap, int), u)))
				return (0);
		if (**format == 'u')
			if (!(ft_u_func(va_arg(ap, unsigned int), u)))
				return (0);
		if (**format == 'x' || **format == 'X')
			if (!(ft_x_func(va_arg(ap, unsigned int), **format, u)))
				return (0);
	}
	return (1);
}
