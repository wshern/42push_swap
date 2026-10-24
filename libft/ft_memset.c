/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukperei <lukperei@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:10:24 by lukperei          #+#    #+#             */
/*   Updated: 2026/08/06 20:10:26 by lukperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n > 0)
	{
		*temp = (unsigned char)c;
		temp++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
int main() {
    // Test 1: Clearing a string/char array
    char str[] = "Hello, World!";
	char str1[] = "Hello, World!";
    printf("Before: %s\n", str);

    ft_memset(str, 'X', 5);
	memset(str1, 'X', 5);
    printf("After:  %s\n\n", str); // Expected: XXXXX, World!
	printf("After:  %s\n\n", str1);

    // Test 2: Zero-initializing an integer array
    int numbers[5] = {10, 20, 30, 40, 50};
	int numbers1[5] = {10, 20, 30, 40, 50};
    ft_memset(numbers, 0, sizeof(numbers));
	memset(numbers1, 0, sizeof(numbers1));

    printf("Integer array elements after clearing:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]); // Expected: 0 0 0 0 
    }
    printf("\n");

	printf("Integer array elements after clearing:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", numbers1[i]); // Expected: 0 0 0 0
    }
    printf("\n");

    return 0;
}
*/
