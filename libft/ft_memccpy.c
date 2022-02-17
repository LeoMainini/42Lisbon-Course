/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:15:25 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/17 13:12:55 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	*ft_memccpy(void *restrict dest, const void *restrict src,
		int c, size_t n)
{
	size_t	index;
	size_t	c_i;
	char	**b_dest;
	char	**b_src;

	b_dest = (char **)&dest;
	b_src = (char **)&src;
	c_i = -1;
	index = -1;
	while (++index < n)
	{
		(*b_dest)[index] = (*b_src)[index];
		if ((*b_dest)[index] == c)
		{
			c_i = index + 1;
			break ;
		}
	}
	if (c_i == -1)
		return (NULL);
	return (&(*b_dest)[c_i]);
}
