/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:25:41 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:24:33 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*lastmatch;
	unsigned char	result;

	lastmatch = NULL;
	result = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == result)
			lastmatch = (char *)s;
		s++;
	}
	if (result == '\0')
		return ((char *)s);
	return (lastmatch);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "Hello";

	printf("%p\n", (void *)s1);
	printf("%p\n", (void *)(strrchr(s1, 'l')));
	printf("%p\n", (void *)(ft_strrchr(s1, 'l')));
	printf("%p\n", (void *)(strrchr(s1, '\0')));
	printf("%p\n", (void *)(ft_strrchr(s1, '\0')));
}*/
