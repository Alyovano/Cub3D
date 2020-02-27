/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 23:00:25 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/27 11:17:16 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start_lst;
	t_list	*c_lst;
	t_list	*new;

	if (lst && f && del)
	{
		c_lst = lst;
		if (!(start_lst = ft_lstnew(f(c_lst->content))))
			return (NULL);
		while (c_lst->next)
		{
			c_lst = c_lst->next;
			if (!(new = ft_lstnew(f(c_lst->content))))
			{
				ft_lstclear(&start_lst, del);
				return (NULL);
			}
			ft_lstadd_back(&start_lst, new);
		}
		return (start_lst);
	}
	return (NULL);
}
