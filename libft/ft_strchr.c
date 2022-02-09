/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:44:34 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/09 13:32:16 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	**sp;

	sp = (char **)&s;
	i = -1;
	while ((*sp)[++i] != '\0')
		if ((*sp)[i] == c)
			return (&(*sp)[i]);
	if (s[i] == c)
		return (&(*sp)[i]);
	return (NULL);
}

int main(void)
{
	char test[1024] = "0123456789";
	printf("4 leo = %s\n", ft_strchr(test, '4'));
	printf("4 lib = %s\n", strchr(test, '4'));
	printf("h leo = %s\n", ft_strchr(test, 'h'));
	printf("h lib = %s\n", strchr(test, 'h'));
	printf("\\0 leo = %s\n", ft_strchr(test, '\0'));
	printf("\\0 lib = %s\n", strchr(test, '\0'));
}
