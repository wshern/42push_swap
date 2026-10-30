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
#include <limits.h>

void free_split(char **numbers)
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

int is_valid_num(char *str)
{
    int i;

    i = 0;
    if (!str || !str[0])
        return (0);
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return (0);
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