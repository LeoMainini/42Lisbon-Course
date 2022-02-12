/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:30:55 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/12 14:37:31 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}

int main(void)
{
	char *test = malloc(12);
	int	i = -1;
	while (++i < 12)
		test[i] = i + 48;
	printf("%c - %p \n", test[4], test);
	ft_memdel((void **)&test);
	printf("%p", test);
}

