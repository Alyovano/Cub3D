/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:55:30 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/30 23:12:28 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_int(int n)
{
	int		size;

	size = 1;
	if (n < 0)
		size++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*returned_value;
	int		len;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = size_int(n);
	if (!(returned_value = (char*)ft_calloc((size_t)len + 1, sizeof(char))))
		return (NULL);
	i = len - 1;
	if (n < 0)
	{
		n *= -1;
		returned_value[0] = '-';
	}
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
