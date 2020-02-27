/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:52:23 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/23 18:23:28 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*malloc_returned;

	if (!(malloc_returned = (void *)malloc(count * size)))
		return (0);
	ft_bzero(malloc_returned, count * size);
	return (malloc_returned);
}
