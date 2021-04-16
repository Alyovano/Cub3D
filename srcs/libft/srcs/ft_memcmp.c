/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:45:22 by yocapell          #+#    #+#             */
/*   Updated: 2019/12/10 08:10:23 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1cp;
	unsigned char	*s2cp;
	size_t			i;

	if (n == 0 || !s1 || !s2)
		return (0);
	s1cp = (unsigned char	*)s1;
	s2cp = (unsigned char	*)s2;
	i = 0;
	while (s1cp[i] == s2cp[i] && i < n)
	{
		if (s1cp[i] != s2cp[i])
			return (s1cp[i] - s2cp[i]);
		i++;
	}
	return (s1cp[i] - s2cp[i]);
}
