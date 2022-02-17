/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:12:26 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/17 13:13:07 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	**b_s;
	int				index;

	b_s = (unsigned char **)&s;
	index = -1;
	while (++index < (int)n)
		if ((*b_s)[index] == c)
			return ((&(*b_s)[index]));
	return (NULL);
}
