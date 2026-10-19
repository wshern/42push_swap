/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:45:47 by werlim            #+#    #+#             */
/*   Updated: 2026/10/19 17:04:02 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps ps;

	if (ac < 2)
		return (0);
	ps_init(&ps);
	ps_parser(ac, av, &ps);
	assign_rank(ps.a);
	ps_dispatcher(&ps);
	if (ps.bench == 1)
		bench(&ps);
	ps_ndclear(&ps.a);
	ps_ndclear(&ps.b);
	return (0);
}