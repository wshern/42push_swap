/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 14:38:10 by lukperei          #+#    #+#             */
/*   Updated: 2026/10/16 14:38:12 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <limits.h>

int is_valid_num(char *str)
{
    int i;

    i = 0;
    if (!str || !str[0])
        return(0);
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return(0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/* basically just atoi but we need to check for overflows*/
int ps_atoi(const char *str, int *result)
{
    long value;
    int sign;
    int digit;

    value = 0;
    sign = 1;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str)
    {
        digit = *str - '0';
        if (value > 2147483648L / 10 || (value == 2147483648L / 10 && digit > 2147483648L % 10))
            return (0);
        value = value * 10 + digit;
        str++;
    }
    value *= sign;
    if (value < INT_MIN || value > INT_MAX)
        return (0);
    *result = (int)value;
    return (1);
}

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

static void free_split(char **numbers)
{
    int i;

    i = 0;
    while (numbers[i])
    {
        free(numbers[i]);
        i++;
    }
    free(numbers);
}

int has_duplicate(t_node *a, int value)
{
    while (a)
    {
        if (a->data == value)
            return (1);
        a = a->next;
    }
    return (0);
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

int parse_arguments(t_ps *ps, int ac, char **av)
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

/* 
int parse_numbers(t_ps *ps, char *arg)
{
    char **numbers;
    int i;

    numbers = ft_split(arg, ' ');
    if (!numbers)
        return (0);
    i = 0;
    while (numbers[i])
    {
        i++;
    }
}*/