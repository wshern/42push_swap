/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:42:54 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:23:43 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)&big[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{

	printf("START PROGRAM OUTPUT\n\n");

	printf("First Test Case\n");
	char	*str = "Needle in a haystack";
	char	*tofind = "in a";
	printf("Your output is: %s\n", ft_strnstr(str, tofind, 21));
	printf("Expected output is: %s\n\n", strnstr(str, tofind, 21));

	printf("Second Test Case\n");
	char	*str2 = "Needle in a haystack";
	char	*tofind2 = "haym";
	printf("Your output is: ");
	printf("%s\n", ft_strnstr(str2, tofind2, 21));
	printf("Expected output is: %s\n\n", strnstr(str2, tofind2, 21));


	printf("Third Test Case\n");
	char	*str3 = "Needle in a haystack";
	char	*tofind3 = "";
	printf("Your output is: %s\n", ft_strnstr(str3, tofind3, 21));
	printf("Expected output is: %s\n\n", strnstr(str3, tofind3, 21));

	printf("Fourth Test Case\n");
	char	*str4 = "Needle in a haystack";
	char	*tofind4 = "in a";
	printf("Your output is: %s\n", ft_strnstr(str4, tofind4, 7));
	printf("Expected output is: %s\n\n", strnstr(str4, tofind4, 7));

	printf("END PROGRAM OUTPUT\n\n");
}*/
