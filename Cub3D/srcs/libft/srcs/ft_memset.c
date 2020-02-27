/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:02:02 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/30 15:33:31 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cpt;
	unsigned char	*s2;

	if (!b)
		return (NULL);
	s2 = (unsigned char*)b;
	cpt = 0;
	while (cpt < len)
		s2[cpt++] = (unsigned char)c;
	return (s2);
}
