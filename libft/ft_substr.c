/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:11:45 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/17 13:41:39 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	while (s[start + i] != '\0')
		i++;
	result = (char *)malloc(i * (sizeof(*result)));
	if (result == 0)
		return (NULL);
	i = -1;
	while (++i < len - 1 && s[start + i] != '\0')
		result[i] = s[start + i];
	result[i] = '\0';
	return (&result[0]);
}
