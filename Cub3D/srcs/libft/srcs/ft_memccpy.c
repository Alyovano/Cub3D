/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:57:08 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/23 16:01:43 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dstcp;
	unsigned char	*srccp;
	size_t			cpt;

	cpt = 0;
	dstcp = (unsigned char*)dst;
	srccp = (unsigned char*)src;
	if (srccp == dstcp)
		return (dstcp);
	while (cpt < n)
	{
		dstcp[cpt] = srccp[cpt];
		if (srccp[cpt] == (unsigned char)c)
			return ((unsigned char *)(dstcp + (cpt + 1)));
		cpt++;
	}
	return (NULL);
}
