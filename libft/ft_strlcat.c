/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:44:39 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/21 16:10:46 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = 0;
	while (src[j] != '\0' && i < size - 1 && size > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size > 0 && i < size)
		dst[i] = '\0';
	if (i > size)
		return (i - 1 + size);
	return (i);
}
