/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:45:29 by leferrei          #+#    #+#             */
/*   Updated: 2022/04/13 18:29:01 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s && s[size] != '\0')
	{
		if (s[size] == '\n')
			return (size + 1);
		size++;
		
	}
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
	return (area);
}

char	*ft_sj(char *read_data, char *buf)
{
	int		i;
	int 	j;
	char	*result;

	i = 0;
	result = malloc((ft_strlen(read_data) + ft_strlen(buf) + 1));
	if (result == NULL)
		return (NULL);
	while (read_data && read_data[i])
	{
		result[i] = read_data[i];
		i++;
	}
		j = 0;
	while (buf[j])
	{
		result[i++] = buf[j];
		if (buf[j++] == '\n')
			break ;
	}
	result[i] = '\0';
	if (read_data)
		free(read_data);
	return (result);
}

char	*ft_substr(char **s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	size;
	size_t			i;

	if (!*s)
		return (NULL);
	size = (unsigned int)ft_strlen(*s);
	if (start >= size)
		return (NULL);
	i = 0;
	while ((*s)[start + i] != '\0' && i < len)
		i++;
	result = (char *)malloc((i + 1) * sizeof(*result));
	if (result == NULL)
		return (NULL);
	i = -1;
	while ((*s)[start + ++i] != '\0' && i < len)
		result[i] = (*s)[start + i];
	result[i] = '\0';
	free(*s);
	return (result);
}

char	*ft_strchr(const char *s, int c, int buf_size)
{
	int		i;
	char	**sp;

	sp = (char **)&s;
	i = -1;
	while ((*sp)[++i] != '\0')
		if ((*sp)[i] == (unsigned char)c)
			return (&(*sp)[i]);
	if (s[i] == (unsigned char)c && i < buf_size)
		return (&(*sp)[i]);
	return (NULL);
}

