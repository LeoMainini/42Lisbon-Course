/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:49 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/18 17:10:23 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*area;
	size_t	i;

	area = (char *)malloc((count * size) * sizeof(*area));
	if (area == NULL)
		return (NULL);
	i = -1;
	while (++i < count * size)
		area[i] = 0;
	return (&area[0]);
}

char	*ft_strcata(char *dest, const char *src)
{
	int	i;
	int	j;
	char *result;

	i = 0;
	result = (char *)ft_calloc((ft_strlen(dest) + ft_strlen(src) + 1),
			sizeof(*dest));
	i = -1;
	while (dest[++i] != '\0')
		result[i] = ((char *)dest)[i];
	j = 0;
	while (src[j] != '\0' && src[j] != '\n')
	{
		result[i + j] = ((char *)src)[j];
		j++;
	}
	return (result);
}

char *get_next_line(int fd)
{
	static 	int progress;
	char *buf;
	char *result;
	int	i;
	int	j;

	buf = (char *)ft_calloc(2, sizeof(*buf));
	while (1)
	{
		j = 0;
		while (++j <= BUFFER_SIZE)
		{
			progress += read(fd, buf, 1);
			i = 0;
			while (buf[i] && buf[i] != '\n')
				i++;
			printf("i = %d buf = %s\n", i, buf);
			result = ft_strcata(result, buf);
			if (i == 1)
				i = 0;
			else
			{
				free(buf);
				printf("size = %d\n", progress);
				break;
			}
			j = 1;
		}
	}
	return result;

}