/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:56:20 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/08 14:18:12 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *restrict dest, const char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int main(void)
{
	char *test = "Ola o meu nome e leo";
	char pdest[1024];
	char *dest = (char *)malloc(50 * sizeof(*dest));
	dest = ft_strcpy(pdest, test);
	printf("dest = %s\npdest = %s\n", dest, pdest);
}
