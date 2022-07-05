/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:25:02 by leferrei          #+#    #+#             */
/*   Updated: 2022/05/30 16:25:05 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

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
	ft_printf("ERROR\n");
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

static void	check_sort_stack(t_node **a, t_node **b, int max_i)
{
	int	done_sorting;

	done_sorting = 0;
	if (!is_sorted(a, 0) && ft_lstsize(a) < 4)
	{
		while (!done_sorting)
			done_sorting = sort_3(a, max_i);
	}
	else if (!is_sorted(a, 0) && ft_lstsize(a) < 6)
	{
		while (!done_sorting)
			done_sorting = insert_sort(a, b, max_i);
		push_all_a(a, b);
	}
	else if (!is_sorted(a, 0))
		while (!done_sorting)
			done_sorting = predictive_insert_sort(a, b, max_i);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		max_i;
	int		null;

	null = 0;
	b = 0;
	a = 0;
	if (argc < 2)
		return (0);
	max_i = get_and_check_stack(argc, argv, &a, null);
	if (max_i == -1)
		return (0);
	check_sort_stack(&a, &b, max_i);
	ft_lstiterf(&a, &free);
	ft_lstiterf(&b, &free);
}
