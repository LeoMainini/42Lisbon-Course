/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:09:09 by leferrei          #+#    #+#             */
/*   Updated: 2022/07/27 15:09:10 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

void	exec_child(t_vars *data, char **cmd_argv, int i)
{
	if ((i && dup2(STDIN_FILENO, data->xfds[0]) == -1)
		|| (i && i < data->arg_count - 4
			&& dup2(data->xfds[1], STDOUT_FILENO) == -1)
		|| (i && i == data->arg_count - 4
			&& dup2(data->out_fd, STDOUT_FILENO) == -1))
	{
		perror("dup2");
		free_and_exit(data, 1);
		close(data->xfds[0]);
		close(data->fds[0]);
	}
	if (!i && dup2(data->fds[1], STDOUT_FILENO) == -1)
	{

		perror("dup2");
		free_and_exit(data, 1);
	}
	close(data->xfds[0]);
	close(data->xfds[1]);
	close(data->fds[0]);
	close(data->fds[1]);
	if (execve(data->path, cmd_argv, NULL) == -1)
		perror("Failed executing");
	ft_printf("Command not found: %s\n", data->cmds[i][0]);
	free_and_exit(data, 1);
}

void	exec_parent(t_vars *data, int i, int pid)
{
	int		status;

	status = 0;
	close(data->xfds[0]);
	close(data->xfds[1]);
	if (i == data->arg_count - 4)
		waitpid(pid, &status, 0);

	wait(NULL);
	close(data->fds[1]);
}

int	fork_lpipes_execute(t_vars *data, int i)
{
	pid_t	pid;

	if (i)
	{
		data->xfds[0] = data->fds[0];
		if (pipe(data->fds) == -1)
			free_and_exit(data, 1);
		data->xfds[1] = data->fds[1];
	}
	else
	{
		data->xfds[0] = data->in_fd;
		if (pipe(data->fds) == -1)
			free_and_exit(data, 1);
		data->xfds[1] = data->fds[1];
	}
	pid = fork();
	if (pid == -1 && ft_printf("Fork Error\n"))
		return (1);
	else if (pid == 0)
		exec_child(data, data->cmds[i], i);
	else
		exec_parent(data, i, pid);
	return (0);
}
