/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:27:33 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/05 22:27:58 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	int		**p;
	int		bc;

	bc = convert_to_binary(c);
	p = (int **)&s;
	i = 0;
	while (i < n / sizeof(int))
	{
		(*p)[i] = bc;
		i++;
	}
	return (s);
}

int main(void)
{
	int	*leo = (int *)malloc(12 * sizeof(*leo));
	int	*lib = (int *)malloc(12 * sizeof(*lib));
	int	i;

	leo = ft_memset(leo, '4', 0);
	lib = memset(lib, '4', 0);

	i = -1;
	while (++i < 12)
	{
			printf("leo = %d\n", leo[i]);
			printf("lib = %d\n", lib[i]);
	}	
}

