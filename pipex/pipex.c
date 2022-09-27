/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:54:22 by leferrei          #+#    #+#             */
/*   Updated: 2022/07/20 15:54:24 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	int		i;
	t_vars	data;

	if (!init_struct(&data, argc, argv))
		exit(1);
	i = -1;
	path = 0;
	path = find_shell_path(envp);
	if (!path && ft_printf("Error finding shell path\n"))
		free_and_exit(&data, 0);
	while (data.cmds[++i])
	{
		data.path = ft_strjoin(path, data.cmds[i][0]);
		fork_lpipes_execute(&data, i);
		free(data.path);
	}
	while (--i > 0)
		wait(NULL);
	free_and_exit(&data, 0);
}
