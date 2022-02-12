/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:25:02 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/12 14:51:51 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*mema;
	size_t	i;

	mema = (char *)malloc(size * (sizeof(*mema)));
	if (mema == 0)
		return (NULL);
	while (++i < size)
		mema[i] = 0;
	return (mema);
}

int main(void)
{
//	char *test = ft_memalloc(10);
}
