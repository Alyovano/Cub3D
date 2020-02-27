/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:50:46 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/30 15:24:59 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pc_func(char c, t_struct *u)
{
	if (u->flags || u->width)
		ft_width_c_manager(c, u);
	else
		u->i += ft_putcharlen_fd(c, 1);
}

void	ft_c_func(char c, t_struct *u)
{
	if (u->width)
		ft_width_c_manager(c, u);
	else
		u->i += ft_putcharlen_fd(c, 1);
}

void	ft_s_func(char *s, t_struct *u)
{
	!s ? s = "(null)" : 0;
	if (u->precision >= -1)
		ft_s_precision(s, u);
	else if (u->width)
		ft_width_s_manager(s, u);
	else
		u->i += ft_putstrlen_fd(s, 1);
}

void	ft_print_p(char *hex, t_struct *u)
{
	u->i += ft_putstrlen_fd("0x", 1);
	u->i += ft_putstrlen_fd(hex, 1);
}
