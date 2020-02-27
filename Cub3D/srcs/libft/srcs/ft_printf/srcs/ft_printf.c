/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:05:01 by yocapell          #+#    #+#             */
/*   Updated: 2019/12/10 08:40:06 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent_find(char **format, t_struct *u, va_list ap)
{
	if (!(ft_manager(format, u, ap)))
		return (0);
	*format += 1;
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	*u;

	if (!format)
		return (0);
	if (!(u = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	u->i = 1;
	va_start(ap, format);
	while (*(format))
	{
		if (*format == '%')
		{
			u = ft_init_struct(u);
			if (!*(++format))
				break ;
			if (!(ft_percent_find((char**)&format, u, ap)))
				return (0);
		}
		else
			u->i += ft_putcharlen_fd(*(format++), 1);
	}
	va_end(ap);
	free(u);
	return (u->i - 1);
}
