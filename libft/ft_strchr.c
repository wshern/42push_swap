/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:04:13 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:13:24 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	result;

	result = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == result)
			return ((char *)s);
		s++;
	}
	if (result == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "Hello";

	printf("String Head: %p\n", (void *)s1);
	printf("String: %s\n", s1);
	printf("Expected l position: %p\n", (void *)(strchr(s1, 'l')));
	printf("Returned l position: %p\n", (void *)(ft_strchr(s1, 'l')));
	printf("Expected null position: %p\n", (void *)(strchr(s1, '\0')));
	printf("Returned null position: %p\n", (void *)(ft_strchr(s1, '\0')));
}*/
