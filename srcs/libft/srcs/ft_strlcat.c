/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:15:47 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/23 18:09:59 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_total;
	size_t	i;
	size_t	j;

	i = 0;
	if (!dst || !src)
		return (0);
	size_total = ft_strlen(dst) + ft_strlen(src);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	else
	{
		j = ft_strlen(dst);
		while (src[i] != '\0' && j < size - 1)
			dst[j++] = src[i++];
		dst[j] = '\0';
		return (size_total);
	}
}
