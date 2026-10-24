/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:45:39 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:15:08 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (dup == NULL)
		return (NULL);
	return (ft_memcpy(dup, s, len));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1 = "Hello";
	char	*s2 = "World";
	char	*res1 = strdup(s1);
	char	*res2 = strdup(s2);

	for (int i = 0; i < 6; i++)
	{
		printf("%c", res1[i]);
	}
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%c", res2[i]);
	}
	printf("\n");
	free(res1);
	free(res2);
}*/
