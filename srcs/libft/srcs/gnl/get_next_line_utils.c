/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:58:09 by yocapell          #+#    #+#             */
/*   Updated: 2020/01/22 12:18:33 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(const char *s)
{
	size_t		size;

	size = 0;
	if (!s)
		return (0);
	while (s[size] != '\0')
		size++;
	return (size);
}

int		ft_nl_searcher(const void *s, size_t n)
{
	unsigned char	*scp;
	size_t			i;

	scp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (scp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_memcpy_gnl(void *dst, const void *src, size_t n)
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

char	*ft_ndup(char *s1, size_t n)
{
	char		*str;

	if (!s1)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	ft_memcpy_gnl(str, s1, n);
	str[n] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ret_str;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
	{
		free(s1);
		return (ft_ndup(!s1 ? s2 : s1, ft_len(!s1 ? s2 : s1)));
	}
	s1_size = ft_len(s1);
	s2_size = ft_len(s2);
	if (!(ret_str = (char *)malloc((s1_size + s2_size + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy_gnl(ret_str, s1, s1_size);
	ft_memcpy_gnl(ret_str + s1_size, s2, s2_size + 1);
	free(s1);
	return (ret_str);
}
