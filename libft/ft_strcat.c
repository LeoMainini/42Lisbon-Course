/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:07:07 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/17 13:40:30 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *restrict dest, const char *restrict src)
{
	int	index;
	int	jindex;

	index = 0;
	while (dest[index] != '\0')
		index++;
	jindex = -1;
	while (src[++jindex] != '\0')
		dest[index + jindex] = src[jindex];
	dest[jindex + index] = '\0';
	return (dest);
}
