/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:52:05 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/07 19:33:37 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		index;
	char	*temp;
	char	**b_dest;
	char	**b_src;

	b_dest = (char **)&dest;
	b_src = (char **)&src;
	temp = (char *)malloc(n * (sizeof(*temp)));
	index = -1;
	while (++index < n)
		temp[index] = (*b_src)[index];
	index = -1;
	while (++index < n)
		(*b_dest)[index] = temp[index];
	return (&((*b_dest)[0]));
}

int main(void)
{
	char test[] = "0123456789";
	char *leo = (char *)malloc(10);
	char *lib = (char *)malloc(10);

	printf("return leo = %s\n", ft_memmove(leo, test, 1));
	printf("return lib = %s\n", memmove(lib, test, 1));
	printf("leo = %s\n", leo);
	printf("lib = %s\n", lib);
	Bom dia ? como guardar este frase??
}
