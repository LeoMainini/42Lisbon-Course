/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:12:40 by leferrei          #+#    #+#             */
/*   Updated: 2022/07/27 15:12:42 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strfree_join(char **s1, char *s2)
{
	char	*result;

	result = ft_strjoin(*s1, s2);
	free(*s1);
	return (result);
}

void	free_and_exit(t_vars *data, int status)
{
	int	i;
	int	k;

	i = -1;
	while (data->cmds[++i])
	{
		k = -1;
		while (data->cmds[i][++k])
			free(data->cmds[i][k]);
	}
	close(data->fds[0]);
	close(data->in_fd);
	close(data->out_fd);
	exit (status);
}
