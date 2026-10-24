/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 18:25:44 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:25:08 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*res = ft_strtrim("abcHello Worldabc", "abc");
	char	*res2 = ft_strtrim("Hello World", " ");

	printf("%s\n", res);
	printf("%s\n", res2);

	free(res);
	free(res2);
}*/
