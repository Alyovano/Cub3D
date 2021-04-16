/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:48:45 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/23 22:45:59 by yossicapelluto   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*srccp;
	unsigned char	*dstcp;

	if (dst == src || (!dst || !src))
		return (dst);
	srccp = (unsigned char *)src;
	dstcp = (unsigned char *)dst;
	if (dstcp < srccp)
	{
		ft_memcpy(dstcp, srccp, len);
		return (dstcp);
	}
	else
	{
		while (len-- > 0)
			dstcp[len] = srccp[len];
		return (dstcp);
	}
}
