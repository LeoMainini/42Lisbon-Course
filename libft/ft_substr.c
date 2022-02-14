/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:11:45 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/14 14:16:25 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(len + 1 * (sizeof(*result)));
	result[len] = '\0';
	if (result == 0)
		return (NULL);
	i = -1;
	while (++i < len)
		result[i] = s[start + i];
	return (&result[0]);
}

int main(void)
{
	char *test = "Ola sou o leo";
	char *r = ft_substr(test, 4, 3);
	printf("%s\n", r);
}
