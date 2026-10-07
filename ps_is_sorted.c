/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:21:10 by werlim            #+#    #+#             */
/*   Updated: 2026/10/07 22:00:48 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1 = empty list/sorted 
// 0 = not sorted
int	ps_is_sorted(t_node *node)
{
	if (!node)
		return (1);
	while (node->next != NULL)
	{
		if (node->rank < node->next->rank)
			node = node->next;
		else
			return (0);
	}
	return (1);
}
