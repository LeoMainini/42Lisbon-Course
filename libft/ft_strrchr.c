/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:44:34 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/09 13:32:47 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		result;
	char	**sp;

	sp = (char **)&s;
	i = -1;
	result = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			result = i;
	if (s[i] == c)
		return (&(*sp)[i]);
	if (result != -1)
		return (&(*sp)[result]);
	return (NULL);
}

int main(void)
{
	char test[1024] = "0123245267289";
	printf("2 leo = %s\n", ft_strrchr(test, '2'));
	printf("2 lib = %s\n", strrchr(test, '2'));
	printf("h leo = %s\n", ft_strrchr(test, 'h'));
	printf("h lib = %s\n", strrchr(test, 'h'));
	printf("\\0 leo = %s\n", ft_strrchr(test, '\0'));
	printf("\\0 lib = %s\n", strrchr(test, '\0'));
}
