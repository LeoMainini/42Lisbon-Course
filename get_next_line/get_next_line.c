/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:49 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/23 17:16:48 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	while (fd >= 0 && fd < 4096 && BUFFER_SIZE > 0)
	{
		response = read(fd, read_data, BUFFER_SIZE);
		buf = ft_strjoin(&buf, &read_data);
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
		if (response <= 0)
			return (0);
	}
	return (0);
}
