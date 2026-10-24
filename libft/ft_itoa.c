/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 14:31:05 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 15:52:38 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int n)
{
	long long	temp;
	int			count;

	count = 0;
	temp = n;
	if (n == 0)
		return (1);
	if (temp < 0)
	{
		temp = -temp;
		count++;
	}
	while (temp != '\0')
	{
		temp = temp / 10;
		count++;
	}
	return (count);
}

static char	*ft_itoaputnbr(long long nbr, char *str, int len)
{
	if (nbr == '\0')
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		len--;
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	int			len;
	char		*str;

	len = ft_intlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == '\0')
		return (NULL);
	str[len] = '\0';
	nbr = n;
	return (ft_itoaputnbr(nbr, str, len));
}
/*
#include <stdio.h>

int	main(void)
{
	int	arr[3] = {2147483647, -2147483648, 0};

	for (int i = 0; i < 3; i++)
	{
		printf("'%s'", ft_itoa(arr[i]));
	}
	printf("\n");
}
*/
