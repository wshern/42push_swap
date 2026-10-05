/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 17:14:22 by werlim            #+#    #+#             */
/*   Updated: 2026/10/05 18:07:35 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_pass(t_ps *ps, int divide)
{
	int n;

	n = ps->size_a;
	while (n != 0)
	{
		if ((ps->a->rank / divide) % 2 == 0)
			op_pb(ps);
		else if ((ps->a->rank / divide) % 2 == 1)
			op_ra(ps);
		n--;
	}
	while (ps->size_b != 0)
		op_pa(ps);
}