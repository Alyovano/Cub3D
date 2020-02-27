/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:10:37 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/30 14:53:43 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_space(t_struct *u, unsigned int i, int k)
{
	int j;

	j = 0;
	if (u->width < 0)
		u->width *= -1;
	while (j++ < u->width - (int)ft_nbrlen(i) - k && u->i++)
		write(1, " ", 1);
}

void	ft_width_x_space(t_struct *u)
{
	int j;

	j = 0;
	if (u->width < 0)
		u->width *= -1;
	while (j++ < u->width - u->precision && u->i++)
		write(1, " ", 1);
}

void	ft_p_precision(t_struct *u, char *hex)
{
	if (u->precision == 0 && ft_strncmp(hex, "0", ft_strlen(hex)) == 0)
	{
		u->i += ft_putstrlen_fd("0x", 1);
		return (ft_precision_space(u, 0));
	}
	if (u->precision < (int)ft_strlen(hex) + 2)
		u->precision = (int)ft_strlen(hex) + 2;
	if (u->precision != -1 && u->flags == '-')
	{
		u->i += ft_putstrlen_fd("0x", 1);
		ft_prec_p_zero(u, hex);
		ft_precision_space(u, 0);
	}
	else
	{
		ft_precision_space(u, 0);
		u->i += ft_putstrlen_fd("0x", 1);
		ft_prec_p_zero(u, hex);
	}
}
