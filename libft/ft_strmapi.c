/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:45:23 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:18:42 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	size_t				len;
	unsigned int		i;

	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (str == '\0')
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>

char	capitalize_odd(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
		{
			c -= 32;
		}
	}
	return (c);
}

int	main(void)
{
	char	*s1 = "Hello";
	char	*res = ft_strmapi(s1, &capitalize_odd);

	for (int i = 0; i < 6; i++)
	{
		printf("%c", res[i]);
	}
	printf("\n");
	free(res);
}*/