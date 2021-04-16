/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:58:44 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/21 16:12:33 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlen(long long nbr)
{
	size_t	size;

	size = 1;
	if (nbr < 0)
		size++;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}
