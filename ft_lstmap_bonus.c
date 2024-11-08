/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:39:06 by jvarila           #+#    #+#             */
/*   Updated: 2024/11/08 13:46:55 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*first;
	t_list	*lst_iter;

	lst_iter = lst;
	node = f(lst_iter->content);
	if (!node)
		return (NULL);
	first = node;
	lst_iter = lst_iter->next;
	while (lst_iter)
	{
		node->next = f(lst_iter->content);
		if (!node->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		node = node->next;
		lst_iter = lst_iter->next;
	}
	return (first);
}
