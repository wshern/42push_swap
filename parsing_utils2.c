/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werlim <werlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:38:10 by lukperei          #+#    #+#             */
/*   Updated: 2026/10/20 15:47:14 by werlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse_flag(t_ps *ps, char *arg, int *strat_set)
{
    if (ft_strncmp(arg, "--simple", 9) == 0)
    {
        if (*strat_set)
            return (-1);
        ps->type_strat = STRAT_SIMPLE;
        *strat_set = 1;
    }
    else if (ft_strncmp(arg, "--medium", 9) == 0)
    {
        if (*strat_set)
            return (-1);
        ps->type_strat = STRAT_MEDIUM;
        *strat_set = 1;
    }
    else if (ft_strncmp(arg, "--complex", 10) == 0)
    {
        if (*strat_set)
            return (-1);
        ps->type_strat = STRAT_COMPLEX;
        *strat_set = 1;
    }
    else if (ft_strncmp(arg, "--adaptive", 11) == 0)
    {
        if (*strat_set)
            return (-1);
        ps->type_strat = STRAT_ADAPTIVE;
        *strat_set = 1;
    }
    else if (ft_strncmp(arg, "--bench", 8) == 0)
        ps->bench = 1;
    else if (arg[0] == '-' && arg[1] == '-')
        return (-1);
    else
        return (0);
    return (1);
}

int parse_numbers(t_ps *ps,char *arg)
{
    char **numbers;
    t_node *new_node;
    int i;
    int value;

    numbers = ft_split(arg, ' ');
    if (!numbers)
        return (0);
    i = 0;
    while (numbers[i])
    {
        if (!is_valid_num(numbers[i]))
        {
            free_split(numbers);
            return (0);
        }
        if (!ps_atoi(numbers[i], &value))
        {
            free_split(numbers);
            return (0);
        }
        if (has_duplicate(ps->a, value))
        {
            free_split(numbers);
            return (0);
        }
        new_node = ps_ndnew(value, 0);
        if (!new_node)
        {
            free_split(numbers);
            return (0);
        }
        ps_ndaddlast(&ps->a, new_node);
        ps->size_a++;
        i++;
    }
    free_split(numbers);
    return (1);
}

int ps_parser(t_ps *ps, int ac, char **av)
{
    int i;
    int strat_set;
    int flag;

    i = 1;
    strat_set = 0;
    while (i < ac)
    {
        flag = parse_flag(ps, av[i], &strat_set);
        if (flag == -1)
            return (0);
        if (flag == 0)
        {
            if (!parse_numbers(ps, av[i]))
                return (0);
        }
        i++;
    }
    return (1);
}