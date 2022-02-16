/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:52:05 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/16 14:43:54 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest > src)
	{
		i = (int)n;
		while (--i >= 0)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		i = -1;
		while (++i < (int)n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}

int main(void)
{
	char test[] = "0123456789";
	char test2[] = "0123456789";
	char *leo = &test[3];
	char *lib = &test2[3];

	printf("return leo = %s\n", (char *)ft_memmove(leo, test, 5));
	printf("return lib = %s\n", (char *)memmove(lib, test2, 5));
	printf("leo = %s\n", leo);
	printf("lib = %s\n", lib);
}
