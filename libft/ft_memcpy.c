/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:01:11 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/17 13:39:26 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char	**b_src;
	char	**b_dest;
	size_t	index;

	b_dest = (char **)&dest;
	b_src = (char **)&src;
	index = -1;
	printf("index = %d\n", index);
	while (++index < n)
		(*b_dest)[index] = (*b_src)[index];
	return (&((*b_dest)[0]));
}
