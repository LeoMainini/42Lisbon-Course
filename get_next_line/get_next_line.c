/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:49 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/21 17:33:00 by leferrei         ###   ########.fr       */
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
char	*ft_strdup(const char *s)
{
	int		size;
	char	*r;

	size = 0;
	while (s[size] != '\0')
		size++;
	r = (char *)malloc(size + 1 * (sizeof(*r)));
	if (r == NULL)
		return (NULL);
	r[size] = '\0';
	size = -1;
	while (s[++size] != '\0')
		r[size] = s[size];
	return (r);
}

char	*attatch_start(char *start, char *rest)
{
	int		i;
	char	*first;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	first = ft_strdup(&start[i + 1]);	
	free(start);
	return (ft_strcata(first, rest));
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	**sp;

	sp = (char **)&s;
	i = -1;
	while ((*sp)[++i] != '\0')
		if ((*sp)[i] == (unsigned char)c)
			return (&(*sp)[i]);
	if (s[i] == (unsigned char)c)
		return (&(*sp)[i]);
	return (NULL);
}

char *get_next_line(int fd)
{
	int	response;
	char *buf;
	static char *start;
	char *result;
	int	i;

	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(*buf));
	while (1 && fd >= 0 && BUFFER_SIZE > 0)
	{
		response = read(fd, buf, BUFFER_SIZE);

		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		result = ft_strcata(result, buf);
		if (i == BUFFER_SIZE)
			i = 0;
		else
		{
			if (ft_strchr(buf, '\n'))
				start = ft_strdup(buf);
			else
				result = attatch_start(start, result);
			break;
		}
	}
	if (response > 0)
		return (result);
	return (NULL);
}
