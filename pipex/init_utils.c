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
