/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:56:04 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/10 13:03:08 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int main(void)
{
	printf("%d\n", ft_isalpha('3'));
	printf("%d\n", isalpha('3'));
	printf("%d\n", ft_isalpha('H'));
	printf("%d\n", isalpha('H'));
	printf("%d\n", ft_isalpha(0));
	printf("%d\n", isalpha(0));
}
