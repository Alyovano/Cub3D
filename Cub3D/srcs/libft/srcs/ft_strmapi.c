/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:41:27 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/30 23:15:08 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		cnt;
	char	*s_cp;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(s_cp = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	cnt = 0;
	while (s[cnt] != '\0')
	{
		s_cp[cnt] = (*f)(cnt, s[cnt]);
		cnt++;
	}
	s_cp[cnt] = '\0';
	return (s_cp);
}
