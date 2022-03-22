/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:49 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/22 18:30:41 by leferrei         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	if (!s2)
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i] != '\0')
			i++;
	j = 0;
	while (s2[j] != '\0')
		j++;
	result = (char *)malloc((i + j + 1) * sizeof(*result));
	if (result == NULL)
		return (NULL);
	result[i + j] = '\0';
	k = -1;
	while (i > 0 && s1[++k] != '\0')
		result[k] = s1[k];
	k = -1;
	while (s2[++k] != '\0')
		result[i + k] = s2[k];
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
	return (ft_strjoin(first, rest));
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
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	size;
	size_t			i;

	if (!s)
		return (NULL);
	size = (unsigned int)ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] != '\0' && i < len)
		i++;
	result = (char *)malloc((i + 1) * sizeof(*result));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (s[start + ++i] != '\0' && i < len)
		result[i] = s[start + i];
	result[i] = '\0';
	if (start > 0)
		free(s);
	return (result);
}



char *get_next_line(int fd)
{
	int	response;
	static char *buf;
	char *read_data;
	char *result;
	long i;

	result = NULL;
	read_data = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(*buf));
	while (fd >= 0 && BUFFER_SIZE > 0)
	{
		response = read(fd, read_data, BUFFER_SIZE);
		if (response < 0)
			return (0);
		buf = ft_strjoin(buf, read_data);
		if (!buf)
			return (0);
		i = 0;
		if ((i = (long)ft_strchr(buf, '\n')))
		{
			i = i - (long)buf + 1;
			result = ft_substr(buf, 0, i);
			buf = ft_substr(buf, i, ft_strlen(buf));
			return(result);
		}
	}
	return (0);
}
