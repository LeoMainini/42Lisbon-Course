/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 19:02:21 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/06 19:10:06 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		size;
	char	*r;

	while (s[size] == '\0')
		size++;
	r = (char *)malloc(size * (sizeof(*r)) + 1);
	if (r == NULL)
		return (NULL);
	r[size] = '\0';
	size = -1;
	while (s[++size] != '\0')
		r[size] = s[size];
	return (r);
}

int main(void)
{
	printf("leo = %s\n", ft_strdup("ola o meu nome e leo"));
	printf("lib = %s\n", strdup("ola o meu nome e leo"));
}
