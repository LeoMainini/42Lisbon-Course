/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:12:06 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/09 13:34:59 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	**r;

	r = (char **)&haystack;
	if (needle[0] == '\0')
		return (&(*r)[0]);
	i = -1;
	while (haystack[++i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0')
		{
			if (needle[j + 1] == '\0')
				return (&(*r)[i]);
			j++;
		}	
	}
	return (NULL);
}

int main(void)
{
	char test[1024] = "Ola o meu nome e leo!";
	printf("'o 'leo = %s\n", ft_strstr(test, "o "));
	printf("'o 'lib = %s\n", strstr(test, "o "));
	printf("''leo = %s\n", ft_strstr(test, ""));
	printf("''lib = %s\n", strstr(test, ""));
	printf("'!'leo = %s\n", ft_strstr(test, "!"));
	printf("'!'lib = %s\n", strstr(test, "!"));
	printf("'nome'leo = %s\n", ft_strstr(test, "nome"));
	printf("'nome'lib = %s\n", strstr(test, "nome"));
	printf("'lol nao tou la'leo = %s\n", ft_strstr(test, "lol nao tou la"));
	printf("'lol nao tou la'lib = %s\n", strstr(test, "lol nao tou la"));
}
