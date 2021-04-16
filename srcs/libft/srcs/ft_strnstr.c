/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:57:00 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/25 14:26:43 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cpt;
	size_t	size;

	if (!haystack || !needle)
		return (NULL);
	if (!(*needle))
		return ((char*)haystack);
	if (len == 0)
		return (NULL);
	cpt = 0;
	size = ft_strlen(needle);
	if (len < size)
		return (NULL);
	while (*haystack != '\0' && cpt <= (len - size))
	{
		if (ft_strncmp(haystack, needle, size) == 0)
			return (char*)(haystack);
		haystack++;
		cpt++;
	}
	return (NULL);
}
