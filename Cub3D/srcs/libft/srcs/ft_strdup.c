/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:18:53 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/27 12:45:11 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*str;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1) + 1;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (0);
	ft_strlcpy(str, s1, i);
	return (str);
}
