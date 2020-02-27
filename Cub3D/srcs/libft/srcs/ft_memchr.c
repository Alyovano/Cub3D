/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:25:50 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/17 20:35:35 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scp;
	size_t			i;

	scp = (unsigned char *)s;
	i = 0;
	if (!scp)
		return (NULL);
	while (i < n)
	{
		if (scp[i] == (unsigned char)c)
			return (scp + i);
		i++;
	}
	return (NULL);
}
