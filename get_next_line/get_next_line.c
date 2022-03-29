/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:49 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/29 21:54:50 by leferrei         ###   ########.fr       */
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
	if (start > 0)
		free(*s);
	return (result);
}

void ft_putstr(char *str);

char *get_next_line(int fd)
{
	int	response;
	static char *buf[1024];
	char *read_data;
	char *result;
	long i;

	result = NULL;
	while (fd >= 0 && fd < 1024 && BUFFER_SIZE > 0)
	{
		read_data = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(*buf));
		response = read(fd, read_data, BUFFER_SIZE);
		buf[fd] = ft_strjoin(&buf[fd], &read_data);
		if (!buf[fd])
			return (0);
		i = 0;
		if ((i = (long)ft_strchr(buf[fd], '\n', ft_strlen(buf[fd]))))
		{
			i = i - (long)buf[fd] + 1;
			result = ft_substr(&buf[fd], 0, i);
			buf[fd] = ft_substr(&buf[fd], i, ft_strlen(buf[fd]));
			free(read_data);
			ft_putstr("with \\n ");
			return(result);
		}
		else if ((i = (long)ft_strchr(buf[fd], '\0', ft_strlen(buf[fd])))
				|| (ft_strlen(read_data) < BUFFER_SIZE
					&& ft_strlen(read_data) > 0))
		{
			ft_putstr("no \\n ");
			free(read_data);
			return (ft_substr(&buf[fd], 0, ft_strlen(buf[fd])));
		}
		if (response <= 0)
		{
			ft_putstr("response <= 0 ");
			free(read_data);
			free(buf[fd]);
			return (0);	
		}
		free(read_data);
	}
	free(buf[fd]);
	return (0);
}
