/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/5 14:38:10 by lukperei           #+#    #+#             */
/*   Updated: 2026/10/10 14:38:12 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void medium_sort(t_ps *ps)
{
    int size;
    int chunk_size;
    int start;
    int end;

    size = ps->size_a;
    chunk_size = get_chunk_size(size);
    start = 0;
    end = chunk_size;

    while (start < size)
    {
        while (chunk_remainder(ps->a, start, end))
        {
            if (in_chunk(ps->a, start, end))
                op_pb(ps);
            else
                op_ra(ps);
        }
        start += chunk_size;
        end += chunk_size;
    }
    push_sorted_b(ps);
}