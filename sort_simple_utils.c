/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/5 14:38:10 by lukperei           #+#    #+#             */
/*   Updated: 2026/10/8 14:38:12 by lukperei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_node *a)
{
    int max;

    max = a->data;
    while (a)
    {
        if (a->data > max)
        max = a->data;
        a = a->next;
    }
    return (max);
}

int find_min(t_node *a)
{
    int min;

    min = a->data;
    while (a)
    {
        if (a->data < min)
            min = a->data;
        a = a->next;
    }
    return (min);
}

int find_min_position(t_node *a)
{
    int min;
    int position;
    int min_position;

    min = a->data;
    position = 0;
    min_position = 0;
    while (a)
    {
        if (a->data < min)
        {
            min = a->data;
            min_position = position;
        }
        position++;
        a = a->next;
    }
    return (min_position);
}

void move_min_top(t_ps *ps)
{
    int position;
    int count;

    position = find_min_position(ps->a);
    if (position <= ps->size_a / 2)
    {
        while (position > 0)
        {
            op_ra(ps);
            position--;
        }
    }
    else
    {
        count = ps->size_a - position;
        while (count > 0)
        {
            op_rra(ps);
            count--;
        }
    }
}