/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:19:51 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/10 13:30:11 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
#include <ctype.h>
int main(void)
{
	int	i = -1;
	
	while(++i <= 127)
		if (isprint(i) == 0)
			printf("%d is not printable \n", i);
	i = -1;
	while(++i <= 127)
		if (isspace(i))
			printf("%d is space\n", i);
	
}

*/

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

int main(void)
{
	ft_isprint('	');
	ft_isspace(' ');
}
