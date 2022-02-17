/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:07:07 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/17 13:21:25 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *restrict dest, const char *restrict src, size_t n)
{
	size_t	index;
	size_t	jindex;

	index = 0;
	while (dest[index] != '\0')
		index++;
	jindex = -1;
	while (src[++jindex] != '\0' && jindex < n)
		dest[index + jindex] = src[jindex];
	dest[jindex + index] = '\0';
	return (dest);
}
