/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:55:21 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/14 15:45:14 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cp_lst;

	if (lst && f)
	{
		cp_lst = lst;
		while (cp_lst)
		{
			f(cp_lst->content);
			cp_lst = cp_lst->next;
		}
	}
}
