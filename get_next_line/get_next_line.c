/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:49 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/30 18:33:23 by leferrei         ###   ########.fr       */
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
	static char buf[1024][BUFFER_SIZE];
	char *read_data;
	char *result;
	long i;

	result = NULL;
	while (fd >= 0 && fd < 1024 && BUFFER_SIZE > 0)
	{
		//TODO: Change return string from buff to read_data

		read_data = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(*buf));
		response = read(fd, read_data, BUFFER_SIZE);
		buf[fd] = ft_strjoin(&buf[fd], &read_data);
		if (!buf[fd])
			return (0);
		i = 0;
		if ((i = (long)ft_strchr(buf[fd], '\n', ft_strlen(buf[fd]))))
		{	
			ft_putstr("found \\n ");
			i = i - (long)buf[fd] + 1;
			result = ft_substr(&buf[fd], 0, i);
			buf[fd] = ft_substr(&buf[fd], i, (ft_strlen(buf[fd])
					- ft_strlen(result)) + 1);
			return(result);
		}
		else if (response > 0 && response < BUFFER_SIZE)
		{
			ft_putstr("stoped reading before buffer ");
			return (ft_substr(&buf[fd], 0, ft_strlen(buf[fd])));
		}

		else if(response <= 0)
		{
			free(buf[fd]);
			ft_putstr("end of read ");
			return (0);	
		}
	}
	return (0);
}

