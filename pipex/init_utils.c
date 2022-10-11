/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:08:53 by leferrei          #+#    #+#             */
/*   Updated: 2022/07/27 15:08:55 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line/get_next_line.h"

char	*ft_strfreedup(char *s)
{
	int		i;
	char	*res;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	i = -1;
	while (s[++i] != 0)
		res[i] = s[i];
	res[i] = 0;
	free(s);
	return (res);
}

char	**parse_stdin_tolimit(char *limiter)
{
	char	**lines_in;
	char	**temp;
	char 	*temp1;
	int		k;
	int		i;

	lines_in = (char **) malloc(2 * sizeof(char *));
	lines_in[1] = 0;
	k = 0;
	lines_in[k] = get_next_line(STDIN_FILENO);
	while (lines_in[k++])
	{
		lines_in[k] = ft_strfreedup(get_next_line(STDIN_FILENO));
		temp1 = ft_strjoin(limiter, "\n");
		if (!ft_strcmp(lines_in[k], temp1))
		{
			free(lines_in[k]);
			free(temp1);
			lines_in[k] = 0;
			break ;
		}
		free(temp1);
		temp = (char **) malloc((k + 2) * sizeof(char *));
		i = -1;
		while (++i <= k)
			temp[i] = ft_strfreedup(lines_in[i]);
		temp[i] = 0;
		free(lines_in);
		lines_in = (char **) malloc((k + 3) * sizeof(char *));
		i = -1;
		while (++i <= k)
			lines_in[i] = ft_strfreedup(temp[i]);
		free(temp);
	}
	return (lines_in);
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
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		data->lines_in = parse_stdin_tolimit(argv[2]);
		data->here_doc = 1;
		data->cmds = get_hd_commands(argc, argv);
	}
	else
	{
		data->here_doc = 0;
		data->lines_in = 0;
		data->in_fd = open(argv[1], O_RDONLY);
		if (data->in_fd < 0 && ft_printf("ERROR:\tIncorrect input file path\n"))
			return (0);
		data->cmds = get_commands(argc, argv);
	}
	if (!data->cmds && ft_printf("ERROR:\tArgument parsing error\n"))
		return (0);
	data->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (data->out_fd < 0 && ft_printf("ERROR:\tOutput file error\n"))
		return (0);
	if (pipe(data->fds) == -1 && ft_printf("Pipe Error\n"))
		return (0);
	if (pipe(data->xfds) == -1 && ft_printf("Pipe Error\n"))
		return (0);
	if (pipe(data->hd_fds) == -1 && ft_printf("Pipe Error\n"))
		return (0);
	return (1);
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
		if (!access(temp, F_OK | X_OK) && !output)
			output = ft_strdup(temp);
		if (temp)
			free(temp);
	}
	if (all_paths)
		free(all_paths);
	if (!output)
		return (0);
	return (clean_path(&output, "ls"));
}

char	*get_pwd(char **envp)
{
	int		i;
	char	*pwd;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PWD", 3))
			pwd = ft_strdup(&envp[i][4]);
	if (pwd)
		return (ft_strfree_join(&pwd, "/"));
	return (0);
}

int	check_file_cmd(t_vars *data, int i)
{
	if (!ft_strchr(data->cmds[i][0], '.') || !ft_strchr(data->cmds[i][0], '/'))
		return (0);
	if (access(data->cmds[i][0], F_OK) && ft_printf("File not found\n"))
		return (0);
	if (access(data->cmds[i][0], X_OK) && ft_printf("File not executable\n"))
		return (0);
	return (1);
}

int	get_path(t_vars *data, int i, char *path, char **envp)
{
	char	*file;

	if (check_file_cmd(data, i))
	{
		data->path = get_pwd(envp);
		file = ft_strtrim(data->cmds[i][0], "./");
		data->path = absolute_to_relative_pwd(data, i, data->path);
		data->path = ft_strfree_join(&data->path, file);
		free(file);
	}
	else
		data->path = ft_strjoin(path, data->cmds[i][0]);
	if (data->path)
		return (1);
	return (0);
}
