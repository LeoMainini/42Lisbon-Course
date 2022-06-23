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

#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"
#include <time.h> //REMOVE

//#TODO:Use split to parse multiple input parameters, atol to check range✅
	//#TODO: Bubble sort through list to check for duplicates and index✅
//#TODO:Throw split output into a✅
//#TODO:Make stack organizing functions✅
//#TODO:Fix leak in split✅
//#TODO:Organize✅
    //#TODO: push to b smallest index (index == 0) in stack a, after calculating✅
		//#TODO: smallest rotate steps using counter in loop that looks for index, keep going until a is sorted
		//#TODO: or reverse sorted, then push all of b to A✅
//#TODO:OPTIMIZE 100s✅
//#TODO:OPTIMIZE ALL ✅
//#TODO: FIX DOUBLE FREE ON EMPTY ARGV INPUT

void    check_free_output(char ***output, int k)
{
	while (*output && **output && k > 0)
		free((*output)[--k]);
    if (*output)
    	free(*output);
	*output = NULL;
}

int	error_out_free(node **stack, char ***output, int k)
{
	ft_printf("ERROR\n");
	if (*stack)
		ft_lstiterf(stack, &free);
	if (*output)
		check_free_output(output, k);
	return (-1);
}

int	get_and_check_stack(int argc, char **argv, node **a, int null)
{
	int		i;
	int		k;
	long	num;
	char	**output;

	i = 0;
	//ft_printf("argc = %d\n", argc);
	while (++i < argc)
	{
		output = ft_split(argv[i], ' ', &null);
		//ft_printf("OUTPUT POINTER = %p\n", output);
		if (!*output)
			return (error_out_free(a,  &output, null));
		k = -1;
		while (output[++k])
		{
			num = check_input(output[k]);
			//printf("num = %ld\n", num);
			if (num != -4000000000)
				ft_lstnew((int)num, a);
			else
				return (error_out_free(a, &output, null));
		}
        check_free_output(&output, null);
	}
	i = check_duplicates_and_index(*a);
	if (i == -1)
		return (error_out_free(a, &output, 0));
	return (i);
}

int	main(int argc, char **argv)
{
	node	*a;
	node	*b;
	int		done_sorting;
	int		max_i;
	int		null;

	null = 0;
	b = 0;
	double time_spent = 0.0;//REMOVE
	clock_t begin = clock();//REMOVE

	a = 0;
	if (argc < 2)
		return (0);
	max_i = get_and_check_stack(argc, argv, &a, null);
	if (max_i == -1)
		return (0);
	done_sorting = 0;
	if (!is_sorted(&a, 0) && ft_lstsize(&a) < 4)
	{
		while (!done_sorting)
			done_sorting = sort_3(&a, max_i);
	}
	else if (!is_sorted(&a, 0) && ft_lstsize(&a) < 6)
	{
		while (!done_sorting)
			done_sorting = insert_sort(&a, &b, max_i);
		push_all_a(&a, &b);
	}
	else if (!is_sorted(&a, 0))
		while (!done_sorting)
			done_sorting = predictive_insert_sort(&a, &b, max_i);
	//ft_push_b(&a, &b);
	//ft_printf("STACK A\n");
	//ft_lstiterf(&a, &print_node);
	ft_lstiterf(&a, &free);
	ft_lstiterf(&b, &free);
	clock_t end = clock(); //REMOVE
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;//REMOVE
	//printf("The elapsed time is %f seconds", time_spent);
}
