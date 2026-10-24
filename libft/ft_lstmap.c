/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:31:05 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/05 17:32:09 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpylist;
	t_list	*newnode;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	cpylist = NULL;
	while (lst != NULL)
	{
		newnode = ft_lstnew(f(lst->content));
		if (newnode == NULL)
		{
			ft_lstclear(&cpylist, del);
			return (NULL);
		}
		ft_lstadd_back(&cpylist, newnode);
		lst = lst->next;
	}
	return (cpylist);
}
