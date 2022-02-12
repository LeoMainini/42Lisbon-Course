/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:43:35 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/12 14:49:18 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	str = (char	*)malloc(size *(sizeof(size * *str)));
	i = -1;
	while (++i < size)
		str[i] = '\0';
	return (&str[0]);
}

int main(void)
{
	int	i;
	char	*str = ft_strnew(12);

	i = -1;
	while(++i < 12)
		if (str[i] == '\0')
			printf("\\0 \n");
}
