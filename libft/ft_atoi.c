/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:31:45 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 15:19:38 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	noomb;

	i = 0;
	sign = 1;
	noomb = 0;
	while (nptr[i] >= 9 && nptr[i] <= 13 || nptr[i] == 32 && nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+' && nptr[i] != '\0')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		noomb = 10 * noomb + nptr[i] - '0';	
		i++;
	}
	return (noomb * sign);
}

/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*max = "2147483647";
	char	*min = "-2147483648";
	char	*negative = "--100";
	char	*positive = "++100";
	char	*hasspace = "   100";
	char	*negspace = "   -100";
	char	*z = "0";

	printf("%d\n", atoi(intmax));
	printf("%d\n", ft_atoi(intmax));
	printf("%d\n", atoi(intmin));
	printf("%d\n", ft_atoi(intmin));
	printf("%d\n", atoi(negs));
	printf("%d\n", ft_atoi(negs));
	printf("%d\n", atoi(pos));
	printf("%d\n", ft_atoi(pos));
	printf("%d\n", atoi(space));
	printf("%d\n", ft_atoi(space));
	printf("%d\n", atoi(spaceneg));
	printf("%d\n", ft_atoi(spaceneg));
	printf("%d\n", atoi(zero));
	printf("%d\n", ft_atoi(zero));
}
*/
