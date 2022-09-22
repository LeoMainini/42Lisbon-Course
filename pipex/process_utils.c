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
	ft_printf("EXECUTION OF CHILD STARTING IN INSTANCE %d\n", i);
	close(data->fds[0]);
	if ((i && dup2(STDIN_FILENO, data->xfds[0]) == -1)
		&& ((i < data->arg_count - 4
			&& dup2(data->fds[1], STDOUT_FILENO) == -1)
		|| (i == data->arg_count - 4
			&& dup2(data->out_fd, STDOUT_FILENO) == -1)))
		free_and_exit(data, 2);
	ft_printf("EXECUTION OF CHILD PROCESSING IN INSTANCE %d\n", i);
	//if (!i && dup2(data->fds[1], STDOUT_FILENO) == -1
	//	&& dup2(data->fds[1], STDERR_FILENO) == -1
	//	&& dup2(STDIN_FILENO, data->in_fd) == -1)
	//	free_and_exit(data, 2);
	if (!i)
	{
		ft_printf("DUPING STDOUT TO FDS[1] IN INSTANCE %d\n", i);
		dup2(data->fds[1], STDOUT_FILENO);
		close(data->fds[1]);
		ft_printf("DUPING STDERR TO FDS[1] IN INSTANCE %d\n", i);
		dup2(data->fds[1], STDERR_FILENO);
		ft_printf("DUPING DATA->IN_FD TO STDIN IN INSTANCE %d\n", i);
		dup2(STDIN_FILENO, data->in_fd);
	}
	ft_printf("EXECUTION OF CHILD PROCESSING IN INSTANCE %d\n", i);
	if (!i)
		close(data->in_fd);


	close(data->xfds[0]);
	close(data->xfds[1]);
	ft_printf("EXECUTION OF CHILD READY IN INSTANCE %d\n", i);
	if (execve(data->path, cmd_argv, NULL) == -1)
		perror("Failed executing");
	ft_printf("Command not found: %s\n", data->cmds[i][0]);
	free_and_exit(data, 1);
}

void	exec_parent(t_vars *data, int i, int pid)
{
	int		status;

	status = 0;
	close(data->fds[1]);
	close(data->xfds[0]);
	close(data->xfds[1]);
	close(data->fds[0]);
	if (!i)
		close(data->in_fd);
	if (i == data->arg_count - 4) {
		waitpid(pid, &status, 0);
	}
	ft_printf("FINISHED EXECUTING PARENT INSTANCE %d\n", i);
}

int	fork_lpipes_execute(t_vars *data, int i)
{
	pid_t	pid;

	if (pipe(data->xfds))
		free_and_exit(data, 1);
	//ft_printf("xfds[0] pos pipe = %d in instance %d\n", data->xfds[0], i);
	if (i)
	{
		data->xfds[0] = data->fds[0];
		//ft_printf("xfds[0] pos fds[0] = %d, fds[0] pre pipe = %d in instance %d\n", data->xfds[0], data->fds[0], i);
		if (pipe(data->fds) == -1)
			free_and_exit(data, 1);
		//ft_printf("xfds[0] pos fds[0] = %d, fds[0] pos pipe = %d in instance %d\n", data->xfds[0], data->fds[0], i);
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
