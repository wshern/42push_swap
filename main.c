/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:45:47 by werlim            #+#    #+#             */
/*   Updated: 2026/10/16 18:38:45 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_initialise(t_ps *ps)
{
    ps_memset(ps, 0, sizeof(*ps));
    ps->type_strat = STRAT_ADAPTIVE;
}

int	main(int ac, char **av)
{
    t_ps    ps;

    if (ac == 1)
        return (0);
    ps_initialise(&ps);
    if (!parse_arguements(&ps, ac, av))
    {
        ps_ndclear(&ps,a);
        return (1);
    }
}