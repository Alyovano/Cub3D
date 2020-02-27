/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:12:41 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/30 16:02:50 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_space(t_struct *u, int k)
{
	int j;

	j = 0;
	u->width *= u->width < 0 ? -1 : 1;
	while (j++ < u->width - u->precision - k && u->i++)
		write(1, " ", 1);
}

void	ft_width_zero(t_struct *u, unsigned int i, int k)
{
	int j;

	j = 0;
	while (j++ < u->width - (int)ft_nbrlen(i) - k && u->i++)
		write(1, "0", 1);
}

int		ft_precision_zero(t_struct *u, unsigned int i, char o)
{
	int				j;
	char			*result;

	j = 0;
	while (j++ < u->precision - (int)ft_nbrlen(i) && u->i++)
		write(1, "0", 1);
	if (!(result = o == 'i' ? ft_itoa(i) : ft_uitoa(i)))
		return (0);
	if (!(u->i += ft_putstrlen_fd(result, 1)))
		return (0);
	free(result);
	return (1);
}

void	ft_prec_x_zero(t_struct *u, char *hex)
{
	int j;

	j = 0;
	while (j++ < u->precision - (int)ft_strlen(hex) && u->i++)
		write(1, "0", 1);
	u->i += ft_putstrlen_fd(hex, 1);
}

void	ft_prec_p_zero(t_struct *u, char *hex)
{
	int j;

	j = 0;
	if ((u->precision - (int)ft_strlen(hex) - 2) <= 0)
		u->precision = (int)ft_strlen(hex);
	while (j++ < u->precision - (int)ft_strlen(hex) && u->i++)
		write(1, "0", 1);
	u->i += ft_putstrlen_fd(hex, 1);
}
