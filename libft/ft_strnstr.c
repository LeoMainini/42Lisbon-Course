/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:12:06 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/09 13:34:25 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	**r;

	r = (char **)&big;
	if (little[0] == '\0')
		return (&(*r)[0]);
	i = -1;
	while (big[++i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != '\0')
		{
			if (little[j + 1] == '\0')
				return (&(*r)[i]);
			j++;
		}	
	}
	return (NULL);
}

int main(void)
{
	char test[1024] = "Ola o meu nome e leo!";
	printf("'o 'leo = %s\n", ft_strnstr(test, "o ", 1));
	printf("'o 'lib = %s\n", strstr(test, "o "));
	printf("''leo = %s\n", ft_strnstr(test, "", 1));
	printf("''lib = %s\n", strstr(test, ""));
	printf("'!'leo = %s\n", ft_strnstr(test, "!", 1));
	printf("'!'lib = %s\n", strstr(test, "!"));
	printf("'nome'leo = %s\n", ft_strnstr(test, "nome", 1));
	printf("'nome'lib = %s\n", strstr(test, "nome"));
	printf("'lol nao tou la'leo = %s\n", ft_strnstr(test, "lol nao tou la", 10));
	printf("'lol nao tou la'lib = %s\n", strstr(test, "lol nao tou la"));
}
