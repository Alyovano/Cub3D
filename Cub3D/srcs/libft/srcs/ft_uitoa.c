/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:55:30 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/19 09:09:20 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_int(unsigned int n)
{
	int		size;

	size = 1;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_uitoa(unsigned int n)
{
	char				*returned_value;
	int					len;
	unsigned int		i;

	len = size_int(n);
	if (!(returned_value = (char*)ft_calloc((size_t)len + 1, sizeof(char))))
		return (NULL);
	i = len - 1;
	while (n >= 10)
	{
		returned_value[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	returned_value[i] = (n % 10) + '0';
	returned_value[len] = '\0';
	return (returned_value);
}
