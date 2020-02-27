/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyovano <alyovano@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:19:37 by alyovano          #+#    #+#             */
/*   Updated: 2020/01/22 14:20:43 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s1, size_t n)
{
	char		*str;

	if (!s1)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	ft_memcpy(str, s1, n);
	str[n] = '\0';
	return (str);
}
