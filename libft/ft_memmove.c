/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:16:51 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 15:58:09 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	src[6] = "Hello";
	char	dst[6] = "World";

	char	src2[6] = "Hello";
	char	dst2[6] = "World";

	char	src3[6] = "Hello";
	char	dst3[6] = "World";

	char	src4[6] = "Hello";
	char	dst4[6] = "World";

	char	src5[6] = "Hello";
	char	*dst5 = &src5[1];

	char	src6[6] = "Hello";
	char	*dst6 = &src6[1];


	printf("%s\n", memmove(dst, src, 6));
	printf("%s\n", ft_memmove(dst2, src2, 6));

	printf("%s\n", memmove(dst3, src3, 2));
	printf("%s\n", ft_memmove(dst4, src4, 2));

	printf("%s\n", memmove(dst5, src5, 4));
	printf("%s\n", ft_memmove(dst6, src6, 4));
}*/
