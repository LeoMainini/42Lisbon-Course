/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:27:33 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/07 21:33:28 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/*
int	iter_pow(int nb, int pow)
{
	int	result;

	result = 1;
	while (--pow >= 0)
		result = result * nb;
	return (result);
}

int	convert_to_binary(int c)
{
	int	result;

	result = c * (iter_pow(2, 24) + iter_pow(2, 16) + iter_pow(2, 8) + 1);
	return (result);
}
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	**p;

	p = (char **)&s;
	i = 0;
	while (i < n)
	{
		(*p)[i] = c;
		i++;
	}
	return (s);
}

int main(void)
{
	char	*leo = (char *)malloc(12 * sizeof(*leo));
	char	*lib = (char *)malloc(12 * sizeof(*lib));
	int		i;

	leo = ft_memset(leo, 'T', 10);
	lib = memset(lib, 'T', 10);

	i = -1;
	while (++i < 12)
	{
		printf("leo = %c\n", leo[i]);
		printf("lib = %c\n", lib[i]);
	}	
}

