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
//#TODO:Make stack organizing functions
//#TODO:Organize

int	error_out_free(node **stack)
{
	ft_printf("ERROR\n");
	if (*stack)
		ft_lstiterf(stack, &free);
	return (0);
}

int	get_and_check_stack(int argc, char **argv, node **a)
{
	int		i;
	int		k;
	long	num;
	char	**output;

	i = 0;
	while (++i < argc)
	{
		ft_printf("argv = %s\n", argv[i]);
		output = ft_split(argv[i], ' ');
		k = -1;
		while (output[++k])
		{
			num = check_input(output[k]);
			if (num != -4000000000)
				ft_lstnew(num, a);
			else
				return (error_out_free(a));
		}
		free(output);
	}
	if (!check_duplicates_and_index(*a))
		return (error_out_free(a));
	return (1);
}

int	main(int argc, char **argv)
{
	node	*a;
	node	*b;

	b = 0;
	double time_spent = 0.0;
	clock_t begin = clock();

	a = 0;
	if (argc < 2)
		return (0);
	if (get_and_check_stack(argc, argv, &a))
		ft_printf("size = %d\n", ft_lstsize(a));
	ft_rev_rotate(&a, 'a');
	ft_printf("size = %d\n", ft_lstsize(a));
	ft_rotate(&a, 'a');
	ft_printf("size = %d\n", ft_lstsize(a));
	ft_swap_one(&a, 'a');
	ft_printf("size = %d\n", ft_lstsize(a));
	ft_swap_one(&a, 'a');
	ft_printf("size = %d\n", ft_lstsize(a));
	ft_push_b(&a, &b);
	ft_printf("size = %d\n", ft_lstsize(a));
	ft_printf("size = %d\n", ft_lstsize(b));
	ft_lstiterf(&a, &free);
	ft_lstiterf(&b, &free);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds", time_spent);

}
