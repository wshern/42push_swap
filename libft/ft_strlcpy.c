/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:22:10 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:17:47 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	char		*e;
	const char	*s;

	d = dst;
	e = dst + size;
	s = src;
	while (*s != '\0' && d < e)
	{
		*d = *s;
		d++;
		s++;
	}
	if (d < e)
		*d = 0;
	else if (size > 0)
		d[-1] = 0;
	while (*s != '\0')
		s++;
	return (s - src);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "abcdefghijklmnopqrst";
    char dest[] = "ABCDEFGHIJKLMNOPQRST";
    printf("Source:\t%s\nDest:\t%s\n", str, dest);
    printf("Copying 10 characters, returns length of source: %d\n", ft_strlcpy(dest, str, 10));
    printf("Source:\t%s\nDest:\t", str);
    for(int i = 0; i < 20; i++)
    {
        printf("%c", dest[i]);
    }
    printf("\n");
}*/