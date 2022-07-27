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

//#TODO: Inicialise variable struct
//#TODO: Convert functions to struct datatype
//#TODO: Execute other commands with output of command before

char	**append_item(char **src, char *entry)
{
	int		i;
	int		size;
	char	**output;

	i = -1;
	size = 0;
	while (src[++i] != NULL)
		size += ft_strlen(src[i]);
	output = (char **)ft_calloc(size + ((i + 1) * 8), sizeof(char ));
	i = -1;
	while (src[++i] != NULL)
	{
		output[i] = ft_strdup(src[i]);
		free(src[i]);
	}
	free(src[i]);
	free(src);
	output[i] = ft_strdup(entry);
	output[i + 1] = 0;
	return (output);
}

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

char	*get_output(int fd)
{
	int		read_bytes;
	char	buf[4096];
	char	*output;

	output = 0;
	ft_bzero(buf, 4096);
	read_bytes = read(fd, buf, sizeof(buf) - 1);
	if (read_bytes > 0)
		output = ft_strfree_join(&output, buf);
	while (read_bytes)
	{
		ft_bzero(buf, sizeof(buf));
		read_bytes = read(fd, buf, sizeof(buf) - 1);
		if (read_bytes < 0 && ft_printf("Error reading output"))
			exit(1);
		if (read_bytes && *buf)
			output = ft_strfree_join(&output, buf);
		if (!read_bytes)
			break ;
	}
	return (output);
}

void	exec_child(t_vars *data, char **cmd_argv, int i)
{
	if ((i && dup2(data->xfds[0], STDIN_FILENO) == -1)
		|| (i && i < data->arg_count - 4
			&& dup2(data->xfds[1], STDOUT_FILENO) == -1)
		|| (i && i == data->arg_count - 4
			&& dup2(data->out_fd, STDOUT_FILENO) == -1))
	{
		perror("dup2");
		free_and_exit(data, 1);
	}
	close(data->xfds[0]);
	close(data->xfds[1]);
	if (!i && dup2(data->fds[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_and_exit(data, 1);
	}
	close(data->fds[1]);
	close(data->fds[0]);
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
	pid = fork();
	if (pid == -1 && ft_printf("Fork Error\n"))
		return (1);
	else if (pid == 0)
		exec_child(data, data->cmds[i], i);
	else
		exec_parent(data, i, pid);
	return (0);
}

int	check_cmd_error(char ***cmds, int i, int argc)
{
	int	k;

	if (!cmds[i - 2][0])
	{
		i = 1;
		while (++i < argc - 1)
		{
			k = -1;
			while (cmds[i - 2][++k])
				free(cmds[i - 2][k]);
			free(cmds[i - 2]);
		}
		free(cmds);
		return (1);
	}
	return (0);
}

char	***get_commands(int argc, char **argv)
{
	char	***cmds;
	int		i;

	i = 2;
	while (i < argc - 1)
		++i;
	cmds = (char ***)ft_calloc(i + 1, sizeof(char *));
	if (!cmds)
		return (0);
	i = 1;
	while (++i < argc - 1)
	{
		cmds[i - 2] = ft_split(argv[i], ' ');
		if (check_cmd_error(cmds, i, argc))
			return (0);
	}
	cmds[i - 2] = 0;
	return (cmds);
}

int	init_struct(t_vars *data, int argc, char **argv)
{
	data->cmds = 0;
	if (argc < 5 && ft_printf("ERROR:\tMissing arguments\n"))
		return (0);
	data->arg_count = argc;
	if (!ft_strcmp(argv[1], argv[argc - 1])
		&& ft_printf("ERROR:\tInfile same as outfile\n"))
		return (0);
	data->in_fd = open(argv[1], O_RDONLY);
	if (data->in_fd < 0 && ft_printf("ERROR:\tIncorrect input file path\n"))
		return (0);
	data->cmds = get_commands(argc, argv);
	if (!data->cmds && ft_printf("ERROR:\tArgument parsing error\n"))
		return (0);
	data->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (data->out_fd < 0 && ft_printf("ERROR:\tOutput file error\n"))
		return (0);
	if (pipe(data->fds) == -1 && ft_printf("Pipe Error\n"))
		return (0);
	if (pipe(data->xfds) == -1 && ft_printf("Pipe Error\n"))
		return (0);
	return (1);
}

char	*clean_path(char **dirty_path, char *extra)
{
	char	*eo_path;
	char	*c_path;
	long	size;

	eo_path = ft_strnstr(*dirty_path, extra, ft_strlen(*dirty_path));
	size = (long)eo_path - (long)*dirty_path;
	c_path = (char *)ft_calloc(size + 1, sizeof(char));
	ft_memmove(c_path, *dirty_path, size);
	free(*dirty_path);
	return (c_path);
}

char	*find_shell_path(char **envp)
{
	int		i;
	char	**all_paths;
	char	*output;
	char	*temp;

	i = -1;
	output = 0;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PATH", 4))
			all_paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (all_paths[++i])
	{
		temp = ft_strfree_join(&all_paths[i], "/ls");
		if (!access(temp, F_OK | X_OK))
			output = ft_strdup(temp);
		free(temp);
	}
	free(all_paths);
	return (clean_path(&output, "ls"));
}

void	write_out(t_vars *data)
{
	char	*output;

	output = 0;
	output = get_output(data->fds[0]);
	close(data->fds[0]);
	if (output && *output)
		write(data->out_fd, output, ft_strlen(output));
	free(output);
	close(data->out_fd);
	close(data->in_fd);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	int		i;
	t_vars	data;

	if (!init_struct(&data, argc, argv))
		exit(1);
	i = -1;
	path = find_shell_path(envp);
	while (data.cmds[++i])
	{
		data.path = ft_strjoin(path, data.cmds[i][0]);
		if (!i)
			data.cmds[i] = append_item(data.cmds[i], argv[1]);
		fork_lpipes_execute(&data, i);
		free(data.path);
	}
	free_and_exit(&data, 0);
}
