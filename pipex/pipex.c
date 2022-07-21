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

char	*get_output(int fd)
{
	int		read_bytes;
	char	buf[4096];
	char	*output;

	output = 0;
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

int fork_link_execute(int fds[2], char *path, char **cmd_argv)
{
	pid_t	pid;
	int 	status;

	status = 0;
	if (pipe(fds) == -1 && ft_printf("Pipe Error\n"))
		return (1);
	pid = fork();
	if (pid == -1 && ft_printf("Fork Error\n"))
		return (1);
	else if (pid == 0)
	{
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			exit(1);
		close(fds[1]);
		close(fds[0]);
		execve(path, cmd_argv, NULL);
		exit(0);
	}
	else
	{
		close(fds[1]);
		waitpid(pid, &status, 0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		infile;
	int		outfile;
	char	**cmd_argv;
	char	*path;
	int		fds[2];
	char *output;

	output = 0;
	if (argc < 5 && ft_printf("ERROR:\tMissing arguments\n"))
		exit(1);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0 && ft_printf("ERROR:\tIncorrect input file path\n"))
		exit(1);
	cmd_argv = ft_split(argv[2], ' ');
	cmd_argv = append_item(cmd_argv, argv[1]);
	path = ft_strjoin("/usr/bin/", cmd_argv[0]);
	ft_printf("1\n");
	fork_link_execute(fds, path, cmd_argv);
	infile = -1;
	ft_printf("3\n");
	while (cmd_argv[++infile])
		free(cmd_argv[infile]);
	free(path);
	free(cmd_argv);
	outfile = open(argv[4], O_RDWR|O_CREAT|O_TRUNC, 0666);
	output = get_output(fds[0]);
	close(fds[0]);
	if (output && *output)
	{
		ft_printf("output = %s, size = %d\n", output, ft_strlen(output));
		write(outfile, output, ft_strlen(output));
	}
	close(outfile);
	close(infile);
	free(output);
}

