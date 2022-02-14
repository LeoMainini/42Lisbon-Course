/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:47:09 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/14 12:53:04 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>

void	*calloc(size_t count, size_t size)
{
	char	*area;
	size_t i;

	area = (char *)malloc((count * size) * sizeof(*area));
	i = -1;
	while (++i < count * size)
		area[i] = 0;
	return (&area[0]);
}

int main(void)
{
	calloc(10, 10);
}
