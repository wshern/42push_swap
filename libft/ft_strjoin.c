/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:06:58 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:16:03 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join == '\0')
		return (NULL);
	while (s1[i] != '\0')
	{
		join[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		join[j] = s2[i];
		j++;
		i++;
	}
	join[j] = 0;
	return (join);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "Hello ";
	char	*s2 = "World";
	char	*res = ft_strjoin(s1, s2);

	for (int i = 0; i < 12; i++)
	{
		printf("%c", res[i]);
	}
	printf("\n");
	free(res);
}*/
