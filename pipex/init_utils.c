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
		free(temp);
	}
	free(all_paths);
	if (!output)
		return (0);
	return (clean_path(&output, "ls"));
}
