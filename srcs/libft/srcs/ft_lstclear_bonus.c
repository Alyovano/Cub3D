/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 20:17:27 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/24 15:57:35 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next;

	if (lst && del)
	{
		temp = *lst;
		while (temp)
		{
			next = temp->next;
			ft_lstdelone(temp, del);
			temp = next;
		}
		*lst = NULL;
	}
}
