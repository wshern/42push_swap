/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 19:21:26 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:21:20 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	dump;

	i = 0;
	dlen = 0;
	while (dlen < size && dst[dlen] != '\0')
		dlen++;
	slen = ft_strlen(src);
	if (dlen >= size)
		return (size + slen);
	dump = size - dlen - 1;
	while (src[i] && dump > 0)
	{
		dst[dlen + i] = src[i];
		i++;
		dump--;
	}
	if (dlen + i < size)
		dst[dlen + i] = '\0';
	return (dlen + slen);
}
/*
#include <stdio.h>
#include <string.h>

int		main()
{
	printf("First Test Case\n");
	char	*src = " w,orl.d";
	char	dest[50] = "Hello";
	printf("Your return: %lu\n", ft_strlcat(dest, src, 50));
	printf("Testing null: ");
	for (int i = 0; i < 14; i++)
		 printf("%c", dest[i]);
	printf("\n");

	char	*src2 = " w,orl.d";
	char	dest2[50] = "Hello";
	printf("Intended return: %lu\n", strlcat(dest2, src2, 50));
	printf("Intended null end: ");
		for (int j = 0; j < 14; j++)
		 printf("%c", dest2[j]);
	printf("\n\n");

	printf("Third Test Case\n");
	char	*src5 = " w,orl.d";
	char	dest5[8] = "Hello";
	printf("Your return: %lu\n", ft_strlcat(dest5, src5, 1));
	printf("Testing null: ");
		for (int a = 0; a < 8; a++)
		 printf("%c", dest5[a]);
	printf("\n");

	char	*src6 = " w,orl.d";
	char	dest6[8] = "Hello";
	printf("Intended return: %lu\n", strlcat(dest6, src6, 1));
	printf("Intended null end: ");
		for (int b = 0; b < 8; b++)
		 printf("%c", dest6[b]);
	printf("\n");
}*/
