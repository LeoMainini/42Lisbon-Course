/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:46:57 by leferrei          #+#    #+#             */
/*   Updated: 2022/08/03 17:46:58 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int return_free_3d(char ***temp, int k, int status)
{
	int i;

	i = -1;
	while((*temp)[++i + k])
		if ((*temp)[i + k])
			free(((*temp)[i + k]));
	if (*temp)
		free(*temp);
	return (status);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int k;
	char **temp;

	i = 0;
	temp = 0;
	while (++i < argc)
	{
		if (temp)
			free(temp);
		temp = ft_split(argv[i], ' ');
		k = -1;
		while	(temp[++k])
		{
			if ((k) > 0 && printf("Too many inputs per argument.\n"))
				return (return_free_3d(&temp, k, 0));
			free(temp[k]);
		}
		if (ft_atoi(argv[i]) < 1 && printf("Philos or time cant be 0 or neg\n"))
			return (return_free_3d(&temp, k, 0));
	}
	return (return_free_3d(&temp, 1, 1));
}
