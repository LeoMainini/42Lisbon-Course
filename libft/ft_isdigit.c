/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:56:04 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/10 13:05:25 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int main(void)
{
	printf("%d\n", ft_isdigit('3'));
	printf("%d\n", isdigit('3'));
	printf("%d\n", ft_isdigit('H'));
	printf("%d\n", isdigit('H'));
	printf("%d\n", ft_isdigit(0));
	printf("%d\n", isdigit(0));
}
