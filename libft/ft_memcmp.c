/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:56:48 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 15:56:04 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "ABCD";
	char str1[] = "ABCD";
	int cmp = memcmp(str, str1, 4);
	int mycmp = ft_memcmp(str, str1, 4);

	if (cmp > 0)
		printf("%s > %s\n", str, str1);
	else if (cmp < 0)
		printf("%s < %s\n", str, str1);
	else
		printf("%s = %s\n", str, str1);
	if (mycmp > 0)
        printf("%s > %s\n", str, str1);
    else if (mycmp < 0)
        printf("%s < %s\n", str, str1);
    else
        printf("%s = %s\n", str, str1);

}*/
