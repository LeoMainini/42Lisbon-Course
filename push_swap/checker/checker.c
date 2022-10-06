/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:45:40 by leferrei          #+#    #+#             */
/*   Updated: 2022/10/06 11:45:42 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_free_output(char ***output, int k)
{
	while (*output && **output && k > 0)
		free((*output)[--k]);
	if (*output)
	{
		free(*output);
		*output = NULL;
	}
}

int	error_out_free(t_node **stack, char ***output, int k)
{
	pf_putstr_fd("ERROR\n", STDERR_FILENO, &k);
	k = k -6;
	if (*stack)
		ft_lstiterf(stack, &free);
	if (*output)
		check_free_output(output, k);
	return (-1);
}

int	get_and_check_stack(int argc, char **argv, t_node **a, int null)
{
	int		i;
	int		k;
	long	num;
	char	**output;

	i = 0;
	while (++i < argc)
	{
		output = ft_split(argv[i], ' ', &null);
		if (!*output)
			return (error_out_free(a, &output, null));
		k = -1;
		while (output[++k])
		{
			num = check_input(output[k]);
			if (num != -4000000000)
				ft_lstnew((int)num, a);
			else
				return (error_out_free(a, &output, null));
		}
		check_free_output(&output, null);
	}
	if (check_duplicates_and_index(*a) == -1)
		return (error_out_free(a, &output, 0));
	return (check_duplicates_and_index(*a));
}

int	check_args(int argc, char **argv, t_node **a)
{
	int	i;
	int	max_i;

	i = 0;
	if (argc < 2)
	{
		pf_putstr_fd("Error\n", STDERR_FILENO, &i);
		return (-1);
	}
	max_i = get_and_check_stack(argc, argv, a, i);
	if (max_i == -1)
		return (-1);
	return (max_i);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		max_i;
	int		null;
	char	**inst;

	b = 0;
	a = 0;
	null = -1;
	max_i = check_args(argc, argv, &a);
	if (max_i == -1)
		return (0);
	inst = parse_stdin();
	exec_insts(&inst, &a, &b);
	null = -1;
	while (inst[++null])
		free(inst[null]);
	free(inst);
	if (is_sorted(&a, 0) && !b)
		ft_printf("OK.\n");
	else
		pf_putstr_fd("KO\n", STDERR_FILENO, &null);
	ft_lstiterf(&a, &free);
}
