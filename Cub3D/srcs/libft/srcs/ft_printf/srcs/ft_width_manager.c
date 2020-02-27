/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 10:29:42 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/30 16:32:49 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_c_manager(char c, t_struct *u)
{
	int		i;

	i = 0;
	if (u->flags == '0')
	{
		while (i++ < u->width - 1 && u->i++)
			write(1, "0", 1);
		u->i += ft_putcharlen_fd(c, 1);
		if (u->width < 0)
			ft_width_i_space(0, u, 0);
	}
	else if (!u->flags)
	{
		while (i++ < u->width - 1 && u->i++)
			write(1, " ", 1);
		u->i += ft_putcharlen_fd(c, 1);
		u->width < 0 ? ft_width_i_space(0, u, 0) : 0;
	}
	else
	{
		u->i += ft_putcharlen_fd(c, 1);
		ft_width_i_space(0, u, 0);
	}
}

void	ft_width_s_manager(char *s, t_struct *u)
{
	int	i;

	i = 0;
	u->width <= (int)ft_strlen(s) ? u->width = (int)ft_strlen(s) : 0;
	!s ? ft_s_null_manager(u) : 0;
	if (u->flags == '0')
	{
		while (i++ < u->width - (int)ft_strlen(s) && u->i++)
			write(1, "0", 1);
		u->i += ft_putstrlen_fd(s, 1);
	}
	else if (!u->flags)
	{
		while (i++ < u->width - (int)ft_strlen(s) && u->i++)
			write(1, " ", 1);
		u->i += ft_putstrlen_fd(s, 1);
	}
	else
	{
		u->i += ft_putstrlen_fd(s, 1);
		while (i++ < u->width - (int)ft_strlen(s) && u->i++)
			write(1, " ", 1);
	}
}

int		ft_width_i_manager(int i, t_struct *u)
{
	int		j;
	int		k;
	char	*result;

	j = 0;
	k = ft_treat_neg(&i);
	if (!(result = ft_itoa(i)))
		return (0);
	if (u->flags == '0' && u->width >= 0)
	{
		u->i += k == 1 ? ft_putcharlen_fd('-', 1) : 0;
		ft_width_zero(u, i, k);
		u->i += ft_putstrlen_fd(result, 1);
	}
	else if (!u->flags)
		ft_width_i_manager2(i, u, result, k);
	else
	{
		u->i += k == 1 ? ft_putcharlen_fd('-', 1) : 0;
		u->i += ft_putstrlen_fd(result, 1);
		ft_width_i_space((long long)i, u, k);
	}
	free(result);
	return (1);
}

int		ft_width_i_manager2(int i, t_struct *u, char *result, int k)
{
	if (u->width < 0)
	{
		u->i += k == 1 ? ft_putcharlen_fd('-', 1) : 0;
		u->i += ft_putstrlen_fd(result, 1);
	}
	else
		ft_width_i_space((long long)i, u, k);
	if (u->width < 0)
		ft_width_i_space((long long)(i), u, k);
	else
	{
		u->i += k == 1 ? ft_putcharlen_fd('-', 1) : 0;
		u->i += ft_putstrlen_fd(result, 1);
	}
	return (1);
}

void	ft_width_x_manager(t_struct *u, char c, char *hex_min, char *hex_max)
{
	int		j;

	j = 0;
	u->width *= u->width < 0 ? -1 : 1;
	if (u->flags == '0')
	{
		while (j++ < u->width - (int)ft_strlen(hex_min) && u->i++)
			write(1, "0", 1);
		u->i += c == 'x' ? ft_putstrlen_fd(hex_min, 1) :
			ft_putstrlen_fd(hex_max, 1);
	}
	else if (!u->flags)
	{
		while (j++ < u->width - (int)ft_strlen(hex_min) && u->i++)
			write(1, " ", 1);
		u->i += c == 'x' ? ft_putstrlen_fd(hex_min, 1) :
			ft_putstrlen_fd(hex_max, 1);
	}
	else
	{
		u->i += c == 'x' ? ft_putstrlen_fd(hex_min, 1) :
			ft_putstrlen_fd(hex_max, 1);
		while (j++ < u->width - (int)ft_strlen(hex_min) && u->i++)
			write(1, " ", 1);
	}
}
