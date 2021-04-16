/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:13:43 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/23 15:49:10 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*srccp;
	unsigned char	*dstcp;
	size_t			cpt;

	srccp = (unsigned char*)src;
	dstcp = (unsigned char*)dst;
	cpt = 0;
	if (n == 0 || src == dst)
		return (dst);
	while (cpt < n)
	{
		dstcp[cpt] = srccp[cpt];
		cpt++;
	}
	return (dstcp);
}
