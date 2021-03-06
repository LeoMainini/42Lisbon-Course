/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:05:50 by leferrei          #+#    #+#             */
/*   Updated: 2022/04/13 19:05:55 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			response;
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*read_data;

	read_data = NULL;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	response = 1;
	while (response > 0)
	{
		if (!*buf[fd])
			response = read(fd, buf[fd], BUFFER_SIZE);
		if (response > 0)
			read_data = ft_sj(read_data, buf[fd]);
		if (clean_buf(buf[fd]) || response < 1)
			break ;
	}
	return (read_data);
}
