/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_manager2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:21:44 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/30 16:31:40 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** putstrlen hors if
*/

int		ft_width_u_manager(unsigned int i, t_struct *u)
{
	int		j;
	char	*result;

	j = 0;
	if (!(result = ft_uitoa(i)))
		return (0);
	if (u->flags == '-')
	{
		u->i += ft_putstrlen_fd(result, 1);
		while (j++ < u->width - (int)ft_nbrlen(i) && u->i++)
			write(1, " ", 1);
	}
	else if (!u->flags)
		while (j++ < u->width - (int)ft_nbrlen(i) && u->i++)
			write(1, " ", 1);
	else
		while (j++ < u->width - (int)ft_nbrlen(i) && u->i++)
			write(1, "0", 1);
	if (!(u->flags == '-'))
		u->i += ft_putstrlen_fd(result, 1);
	free(result);
	return (1);
}

void	ft_width_i_space(long long i, t_struct *u, int k)
{
	int		j;

	j = 0;
	if (u->width > 0)
		while (j++ < u->width - (int)ft_nbrlen(i) - k && u->i++)
			write(1, " ", 1);
	else
		while (j-- > u->width + (int)ft_nbrlen(i) - k && u->i++)
			write(1, " ", 1);
}

void	ft_width_p_space(char *hex, t_struct *u)
{
	int		j;

	j = 0;
	if (u->width > 0)
		while (j++ < u->width - ((int)ft_strlen(hex) + 2) && u->i++)
			write(1, " ", 1);
	else
		while (j-- > u->width + ((int)ft_strlen(hex) + 2) && u->i++)
			write(1, " ", 1);
}

void	ft_precision_x_zero(t_struct *u, int k)
{
	int j;

	j = 0;
	u->width *= u->width < 0 ? -1 : 1;
	while (j++ < u->width - u->precision - k && u->i++)
		write(1, "0", 1);
}

void	ft_width_p_manager(t_struct *u, char *hex)
{
	int		j;

	j = 0;
	if (u->flags == '0')
	{
		while (j++ < u->width - ((int)ft_strlen(hex) - 2) && u->i++)
			write(1, "0", 1);
		ft_print_p(hex, u);
	}
	else if (!u->flags)
	{
		u->width > 0 ? ft_width_p_space(hex, u) : 0;
		ft_print_p(hex, u);
		u->width < 0 ? ft_width_p_space(hex, u) : 0;
	}
	else
	{
		ft_print_p(hex, u);
		ft_width_p_space(hex, u);
	}
}
