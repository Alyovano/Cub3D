/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 10:24:23 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/30 21:28:57 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *str, char c)
{
	int		i;
	int		nb_word;

	i = 0;
	nb_word = 0;
	if (!str || str[0] == '\0')
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		nb_word++;
		while (str[i] != c && str[i])
			i++;
	}
	if (str[i - 1] == c)
		nb_word--;
	return (nb_word);
}

static int	count_str_size(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static char	**unmalloc(char **strs, int i)
{
	int		j;

	j = 0;
	while (j < i - 1)
		free(strs[j++]);
	free(strs);
	return (NULL);
}

char		**ft_split(char const *s1, char c)
{
	char	**strs;
	int		nb_word;
	int		str_size;
	int		start;
	int		i;

	i = 0;
	start = 0;
	nb_word = count_word((char*)s1, c);
	if (!s1 || !(strs = (char**)malloc(sizeof(char *) * (nb_word + 1))))
		return ((char**)NULL);
	while (i < nb_word && s1[start] != '\0')
	{
		while (s1[start] == c && s1[start] != '\0')
			start++;
		str_size = count_str_size((char*)s1 + start, c);
		if (!(strs[i++] = ft_substr(s1, start, str_size)))
			return (unmalloc(strs, i));
		start += str_size;
	}
	strs[nb_word] = 0;
	return (strs);
}
