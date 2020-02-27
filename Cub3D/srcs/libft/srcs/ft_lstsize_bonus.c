/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:37:17 by yocapell          #+#    #+#             */
/*   Updated: 2019/10/14 14:16:08 by yocapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*c_lst;
	int		cpt;

	if (!lst)
		return (0);
	cpt = 0;
	c_lst = lst;
	while (c_lst && ++cpt)
		c_lst = c_lst->next;
	return (cpt);
}
