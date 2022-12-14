/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:17:39 by tbrandt           #+#    #+#             */
/*   Updated: 2021/11/02 13:28:45 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*new_link;

	newlist = NULL;
	while (lst)
	{
		new_link = ft_lstnew(f(lst->content));
		if (!new_link)
		{
			del(newlist->content);
			return (NULL);
		}
		ft_lstadd_back(&newlist, new_link);
		lst = lst->next;
	}
	return (newlist);
}
