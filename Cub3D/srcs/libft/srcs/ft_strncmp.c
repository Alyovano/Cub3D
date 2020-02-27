/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:45:02 by yocapell          #+#    #+#             */
/*   Updated: 2019/11/08 12:13:28 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + 1;
	j = ft_strlen(s2) + 1;
	len = i;
	if (j < i)
		len = j;
	if (len < n)
		return (ft_memcmp(s1, s2, len));
	return (ft_memcmp(s1, s2, n));
}
