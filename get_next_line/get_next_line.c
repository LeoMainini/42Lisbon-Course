/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:49 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/29 17:30:53 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char **s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	size;
	size_t			i;

	if (!*s)
		return (NULL);
	size = (unsigned int)ft_strlen(*s);
	if (start >= size)
	{
		free(*s);
		return (NULL);
	}
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
	if (start > 0)
		free(*s);
	return (result);
}



char *get_next_line(int fd)
{
	int	response;
	static char *buf[1024];
	char *read_data;
	char *result;
	long i;

	result = NULL;
	read_data = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(*buf));
	while (fd >= 0 && fd < 1024 && BUFFER_SIZE > 0)
	{
		response = read(fd, read_data, BUFFER_SIZE);
		buf[fd] = ft_strjoin(&buf[fd], &read_data);
		if (!buf[fd])
			return (0);
		i = 0;
		if ((i = (long)ft_strchr(buf[fd], '\n')))
		{
			i = i - (long)buf[fd] + 1;
			result = ft_substr(&buf[fd], 0, i);
			buf[fd] = ft_substr(&buf[fd], i, ft_strlen(buf[fd]));
			free(read_data);
			return(result);
		}
		if (response <= 0)
		{
			free(read_data);
			return (0);	
		}
	}
	free(read_data);
	return (0);
}
