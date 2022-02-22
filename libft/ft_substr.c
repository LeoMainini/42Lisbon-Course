/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:11:45 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/21 18:00:50 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	size;
	size_t	i;

	size = (unsigned int)ft_strlen(s);
	i = 0;
	if (start >= size)
	{
		result = (char *)malloc(1 * sizeof(*result));
		result[0] = '\0';
		return (result);
	}
	if (len > size - start)
		len = size - start;
	while (s[start + i] != '\0')
		i++;
	result = (char *)malloc((i + 1) * sizeof(*result));
	if (result == 0)
		return (NULL);
	i = -1;
	while (++i < len - 1 && s[start + i] != '\0')
		result[i] = s[start + i];
	result[i] = '\0';
	return (&result[0]);
}
