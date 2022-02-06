/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:01:11 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/06 14:16:49 by leferrei         ###   ########.fr       */
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

int	main(void)
{
	char	test[1024] = "0123456789";
	char	dest[1024];
	char	*dest_r = (char *)malloc(1024 * sizeof(*dest_r));
	dest_r = (char *)ft_memcpy(dest, test, 6);
	char dest_l[1024];
	char	*dest_rl = (char *)malloc(1024 * sizeof(*dest_rl));
	dest_rl = (char *)memcpy(dest_l, test, 6);
	printf("dest = %s\ndest_r = %s\n", dest, dest_r);
	printf("dest_l = %s\ndest_rl = %s\n", dest_l, dest_rl);
}

