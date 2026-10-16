/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:45:47 by werlim            #+#    #+#             */
/*   Updated: 2026/10/16 17:32:18 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ps_memset(void *s, int c, size_t n)
{
		unsigned char	*ptr;
		size_t			i;

		i = 0;
		ptr = (unsigned char *)s;
		while (i < n)
				ptr[i++] = (unsigned char)c;
		return (s);
}

void	ps_init(t_ps *ps)
{
	ps_memset(ps, 0, sizeof(*ps));
	ps->type_strat = STRAT_ADAPTIVE;
}

int	main(int ac, char **av)
{}