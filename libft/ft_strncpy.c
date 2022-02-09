/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:56:20 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/08 15:03:01 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *restrict dest, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dest[index] = src[index];
		index++;
	}
	index--;
	while (++index < n)
		dest[index] = '\0';
	return (dest);
}

int main(void)
{
	char *test = "Ola o meu nome e leo";
	char pdest[1024];
	char *dest = (char *)malloc(50 * sizeof(*dest));
	dest = ft_strncpy(pdest, test, 20);
	printf("dest = %s\npdest = %s\n", dest, pdest);
}
