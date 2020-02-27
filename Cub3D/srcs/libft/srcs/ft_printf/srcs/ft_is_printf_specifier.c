/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_printf_specifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:01:31 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/21 09:21:19 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_printf_specifier(char c)
{
	char	*specifier;

	specifier = "cspiduxX%\0";
	while (*specifier != '\0')
	{
		if (*specifier == c)
			return (1);
		specifier++;
	}
	return (0);
}
