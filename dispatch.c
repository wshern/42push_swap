/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 17:21:51 by werlim            #+#    #+#             */
/*   Updated: 2026/10/16 16:43:48 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dispatcher(t_ps *ps)
{
	ps->disorder = calc_disorder(ps->a);
	if (ps->type_strat == STRAT_SIMPLE)
		sort_simple(ps);
	else if (ps->type_strat == STRAT_MEDIUM)
		sort_medium(ps);
	else if (ps->type_strat == STRAT_COMPLEX)
		sort_complex(ps);
	else
		sort_adaptive(ps);
}

// check teammate sorting algo if ps_is_sorted guard is added.
