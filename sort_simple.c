/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:38:10 by ukperei           #+#    #+#             */
/*   Updated: 2026/10/30 11:54:40 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple_all(t_ps *ps)
{
	while (ps->size_a > 0)
	{
		move_min_top(ps);
		op_pb(ps);
	}
	while (ps->size_b > 0)
		op_pa(ps);
}

void    sort_two(t_ps *ps)
{
	if (ps->a->rank > ps->a->next->rank)
		op_sa(ps);
}

void   sort_three(t_ps *ps)
{
	int max;

	max = find_max(ps->a);
	if (ps->a->rank == max)
		op_ra(ps);
	else if (ps->a->next->rank == max)
		op_rra(ps);
	if (ps->a->rank > ps->a->next->rank)
		op_sa(ps);
}

void    sort_four(t_ps *ps)
{
	move_min_top(ps);
	op_pb(ps);
	sort_three(ps);
	op_pa(ps);
}

void    sort_five(t_ps *ps)
{
	move_min_top(ps);
	op_pb(ps);
	move_min_top(ps);
	op_pb(ps);
	sort_three(ps);
	op_pa(ps);
	op_pa(ps);
}

void    sort_simple(t_ps *ps)
{
    ps->type_class = STRAT_SIMPLE;
	if (ps->size_a <= 1)
		return ;
	if (ps->size_a == 2)
		sort_two(ps);
	else if (ps->size_a == 3)
		sort_three(ps);
    else if (ps->size_a == 4)
        sort_four(ps);
	else if (ps->size_a <= 5)
		sort_five(ps);
    else
        sort_simple_all(ps);
}
