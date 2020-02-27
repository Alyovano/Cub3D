/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:23:14 by yocapell          #+#    #+#             */
/*   Updated: 2020/01/10 22:58:51 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*
** Example : ft_int_init(3, &i, 15, &j, 10, &k, 5);
*/

void	ft_int_init(int nb_var, ...)
{
	va_list			ap;
	int				i;
	unsigned int	*get;
	int				tmp;

	if (nb_var == 0)
		return ;
	i = 0;
	get = malloc(sizeof(int *));
	va_start(ap, nb_var);
	while (i < nb_var)
	{
		get = va_arg(ap, unsigned int*);
		tmp = va_arg(ap, int);
		*get = tmp;
		i++;
	}
	va_end(ap);
}
