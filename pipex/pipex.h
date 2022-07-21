/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:08:37 by leferrei          #+#    #+#             */
/*   Updated: 2022/07/20 16:08:38 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct	s_vars {
	char	**cmds;
	int 	fds[2];
	int		infile;
	int 	outfile;
}			t_vars;

#endif