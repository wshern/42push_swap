/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:24:48 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 15:55:25 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	result;

	p = (unsigned char *)s;
	result = (unsigned char)c;
	while (n > 0)
	{
		if (*p == result)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned char	l = 'l';
	unsigned char	H = 'H';
	unsigned char	p = 'p';
	char			s[6] = "Hello";

	printf("%s\n", memchr(s, l, 5));
	printf("%s\n", ft_memchr(s, l, 5));
	printf("%s\n", memchr(s, H, 5));
	printf("%s\n", ft_memchr(s, H, 5));
	printf("%s\n", memchr(s, p, 5));
	printf("%s\n", ft_memchr(s, p, 5));
}
*/
