/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:34:04 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/06 14:19:57 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	**str;

	str = (char **)&s;
	index = 0;
	while (index < n)
	{
		(*str)[index] = '\0';
		index++;
	}
}

int main(void)
{
	char	leo[] = "0123456789";
	char	lib[] = "0123456789";
	int		index = -1;

	ft_bzero(leo, 4);
	bzero(lib, 4);
	while (++index < 10)
	{
		if (leo[index] =='\0')
			write(1, "Leo - \\0\n", 9);
		if	(lib[index] == '\0')
			write(1, "Lib - \\0\n", 9);
		if (lib[index] != '\0' || leo[index] != '\0')
			break;
	}
	while (index < 10)
	{
		write(1, "Leo - ", 6);
		write(1, &leo[index], 1);
		write(1, "\n", 1);
		write(1, "Lib - ", 6);
		write(1, &lib[index], 1);
		write(1, "\n", 1);
		index++;
	}
}
