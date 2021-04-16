/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:54:49 by yocapell          #+#    #+#             */
/*   Updated: 2020/01/22 12:18:08 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_line(char **line, char **stack)
{
	int		i;
	char	*tmp;

	if ((i = ft_nl_searcher(*line, ft_len(*line))) != -1)
	{
		if (*stack)
			free(*stack);
		if (!(*stack = ft_ndup(*line + i + 1, ft_len(*line + i + 1))))
			return (-1);
		if (!(tmp = ft_ndup(*line, i)))
			return (-1);
		free(*line);
		if (!(*line = ft_ndup(tmp, i)))
			return (-1);
		if (tmp)
			free(tmp);
		return (1);
	}
	return (0);
}

int		ft_read(int fd, char **line, int *ret)
{
	char	buf[BUFFER_SIZE + 1];

	if ((read(fd, buf, 0)) == -1)
		return (-1);
	while ((*ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[*ret] = '\0';
		if (!(*line = ft_strjoin_gnl(*line, buf)))
			return (-1);
		if (ft_nl_searcher(*line, ft_len(*line)) != -1)
			break ;
	}
	if (*ret == 0 && ((ft_nl_searcher(*line, ft_len(*line)) == -1)))
		return (0);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*stack[OPEN_MAX];
	int			ret;
	int			i;

	ret = 0;
	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	if (!(*line = stack[fd] ? ft_ndup(stack[fd], ft_len(stack[fd]))
		: ft_ndup("", 0)))
		return (-1);
	if ((i = ft_check_line(line, &stack[fd])) == 0)
	{
		if ((i = ft_read(fd, line, &ret)) == 0)
		{
			free(stack[fd]);
			stack[fd] = NULL;
			return (0);
		}
		if ((ft_check_line(line, &stack[fd]) == -1) || i == -1)
			return (-1);
	}
	if (i == -1)
		return (-1);
	return (1);
}
