/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:52:03 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/12 14:59:39 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_strdel(char	**as)
{
	free(*as);
	*as = NULL;
}

int main(void)
{
	char	*test = malloc(12);
	printf("%p\n", test);
	ft_strdel(&test);
	printf("%p\n", test);
}
