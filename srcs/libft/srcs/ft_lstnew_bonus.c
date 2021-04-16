/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:30:24 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/14 15:54:25 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *list;

	list = NULL;
	if (!(list = malloc(sizeof(t_list))))
		return (0);
	list->content = content;
	list->next = NULL;
	return (list);
}
