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

//#TODO: Missing process forking to get output

char **append_item(char **src, char *entry)
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

int main(int argc, char **argv)
{
	int infile;
	int outfile;
	char **cmd1_argv;
	char *path;

	if (argc < 5 && ft_printf("ERROR:\tMissing arguments\n"))
		return (0);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0 && ft_printf("ERROR:\tIncorrect input file path\n"))
		return (0);
	outfile = open(argv[4], O_WRONLY|O_CREAT);
	cmd1_argv = ft_split(argv[2], ' ');
	cmd1_argv = append_item(cmd1_argv, argv[1]);
	path = ft_strjoin("/usr/bin/", cmd1_argv[0]);
	if (execve(path, cmd1_argv, NULL) == -1)
	{
		perror("Could not execute command");
		int i = -1;
		while (cmd1_argv[++i])
			free(cmd1_argv[i]);
		free(path);
		free(cmd1_argv);
	}
	ft_printf("%d %d %d\n", infile, outfile, argc);
}

