/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:50:47 by yocapell          #+#    #+#             */
/*   Updated: 2020/01/22 12:18:49 by alyovano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

size_t	ft_len(const char *s);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
char	*ft_ndup(char *s1, size_t n);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_nl_searcher(const void *s, size_t n);
int		get_next_line(int fd, char **line);
int		ft_read(int fd, char **line, int *ret);
#endif
