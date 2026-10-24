/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:38:13 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:20:01 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (s1[i] != '\0') && (s1[i] == s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>

int		main()
{
	char	*s1 = "Do what you want cause a pirate is free, you are a pirate!";
	char	*s2 = "Do what you want cause a pirate is free, you are a pirate!";
	printf("Your function returns: %d\n", ft_strncmp(s1, s2, 58));
	printf("Proper function returns: %d\n", strncmp(s1, s2, 58));
	char	*s3 = "Do what you want cause a pirate is free, you are a pirate!";
	char	*s4 = "Do what you want cause a pirate is free, you are a pirate!";
	printf("Your function returns: %d\n", ft_strncmp(s3, s4, 60));
	printf("Proper function returns: %d\n", strncmp(s3, s4, 60));
	char	*s5 = "Do what you want cause a pirate is free, you are a pirate!";
	char	*s6 = "Do what you want cause a p\xFFrate is free, you are a pirate!";
	printf("Your function returns: %d\n", ft_strncmp(s5, s6, 58));
	printf("Proper function returns: %d\n", strncmp(s5, s6, 58));
}*/