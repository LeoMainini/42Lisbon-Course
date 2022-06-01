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

//#TODO:Use split to parse multiple input parameters, atol to check range
//#TODO:Organize indexes of numbers by ascending
//#TODO:Throw split output into a
//#TODO:Make stack organizing functions
//#TODO:Organize

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long check_input(char *nums)
{
	long num;
	int i;

	i = 0;
	if (nums[i] == '-' || nums[i] == '+')
		i++;
	while (is_digit(nums[i]))
		i++;
	if (nums[i] != '\0' || i > 11)
		return (-4000000000);
	num = ft_atol(nums);
	if (num > 2147483647 || num < -2147483648 )
		return (-4000000000);
	return (num);
}

//void init_stacks(ps *stacks)
//{
//	stacks->a = (stack *)malloc(sizeof(stack));
//	stacks->a->start = 0;
//	stacks->a->end = 0;
//	stacks->a->size = 0;
//	stacks->b = (stack *)malloc(sizeof(stack));
//	stacks->b->start = 0;
//	stacks->b->end = 0;
//	stacks->b->size = 0;
//}

int main(int argc, char **argv)
{
	int		i;
	int		k;
	long	num;
	char	**output;
	node	*a;
//	ps		stacks;

//	init_stacks(&stacks);
//	if (!stacks.a || !stacks.b)
//		if (stacks.a)
//			free(stacks.a);
	a = 0;
	if (argc < 2)
		return (0);
	i = 0;
	while (++i < argc)
	{
		output = ft_split(argv[i], ' ');
		k = -1;
		while (output[++k])
		{
			if ((num = check_input(output[k])) != -4000000000)
			{
				ft_lstnew(num, &a);
			}
			else
			{
				ft_printf("ERROR\n");
				return (0);
			}
		}
		ft_printf("size = %d\n", ft_lstsize(a));
	}
	return (0);
}