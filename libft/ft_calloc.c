/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:05:13 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 18:17:10 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;

	if (size != 0 && nmemb > SIZE_MAX)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	if (ptr != NULL)
		ft_memset(ptr, 0, (size * nmemb));
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = calloc(2, 2);
	s2 = ft_calloc(2, 2);

	s1[0] = 'a';
	s1[2] = 'a';
	s2[0] = 'a';
	s2[2] = 'a';

	for (int i = 0; i < 4; i++)
	{
		printf("%c", s1[i]);
	}
	printf("\n");

	for (int j = 0; j < 4; j++)
	{
		printf("%c", s2[j]);
	}
	printf("\n");

	free(s1);
	free(s2);
}
*/
