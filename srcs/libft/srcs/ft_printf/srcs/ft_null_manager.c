/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:40:35 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/30 15:11:05 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_null_manager(t_struct *u)
{
	int	i;

	i = 0;
	if (u->flags == '0')
	{
		while (i++ < u->width - 6 && u->i++)
			write(1, "0", 1);
		write(1, "(null)", 6);
		u->i++;
	}
	else if (!u->flags && u->width)
	{
		while (i++ < u->width - 6 && u->i++)
			write(1, " ", 1);
		write(1, "(null)", 6);
		u->i++;
	}
	else
		ft_s_null_manager2(u, i);
}

void	ft_s_null_manager2(t_struct *u, int i)
{
	if (u->flags == '-')
	{
		write(1, "(null)", 6);
		u->i++;
		while (i++ < u->width - 6 && u->i++)
			write(1, " ", 1);
	}
	else
	{
		write(1, "(null)", 6);
		u->i++;
	}
}
