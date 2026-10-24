/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:19:49 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 18:29:13 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (*s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	memfree(char **array, int count)
{
	while (count > 0)
	{
		count--;
		free(array[count]);
	}
	free(array);
}

static int	memafail(char **array, int count)
{
	if (array[count] == (NULL))
	{
		memfree(array, count);
		return (0);
	}
	return (1);
}

static char	**fillarray(char **array, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	arraycount;

	i = 0;
	arraycount = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			array[arraycount] = ft_substr(s, start, i - start);
			if (memafail(array, arraycount) == 0)
				return (NULL);
			arraycount++;
		}
		else
			i++;
	}
	array[arraycount] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	size;

	if (s == NULL)
		return (0);
	size = wordcount(s, c) + 1;
	array = (char **)malloc(sizeof(char *) * size);
	if (array == NULL)
		return (0);
	array = fillarray(array, s, c);
	return (array);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "Hello world, this is a test string";
	char	**res = ft_split(s1, ' ');

	if (!res)
	{
		printf("Allocation failed or returned NULL\n");
		return(1);
	}
	for (int i = 0; i < 8; i++)
	{
		printf("%s\n", res[i]);
		free(res[i]);
	}
	free(res);
}*/
