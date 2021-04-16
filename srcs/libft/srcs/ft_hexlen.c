/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:45:07 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/21 21:51:29 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_hexlen(long long nbr)
{
	size_t	size;

	size = 1;
	if (nbr < 0)
		size++;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 16;
		size++;
	}
	return (size);
}
