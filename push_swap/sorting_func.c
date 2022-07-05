/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:36:15 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/03 23:36:18 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size_sort_index(t_node *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = ft_lstsize(&stack);
	return (size);
}

int	is_sorted(t_node **stack, int reverse)
{
	t_node	*temp;

	if (!*stack)
		return (0);
	temp = (*stack);
	while (!reverse && temp != (*stack)->prev)
	{
		if (temp->next->number < temp->number)
			return (0);
		temp = temp->next;
	}
	while (reverse && temp != (*stack)->prev)
	{
		if (temp->next->number > temp->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_circular_sorted(t_node **stack, int max_i)
{
	int		i;
	int		k;
	t_node	*temp;

	temp = *stack;
	i = 0;
	k = 1;
	while (temp->index < temp->next->index && temp->index != max_i)
	{
		temp = temp->next;
		k++;
	}
	temp = temp->next;
	while (temp->index < temp->next->index)
	{
		temp = temp->next;
		i++;
	}
	if (max_i == i)
		return (k);
	return (0);
}

static void	compute_exec_move(t_node **stack_a, int index)
{
	int		i;
	int		size;
	t_node	*temp;

	size = get_size_sort_index(*stack_a);
	i = 0;
	temp = (*stack_a)->next;
	while (temp != *stack_a)
	{
		i++;
		if (temp->index == index)
			break ;
		temp = temp->next;
	}
	if ((*stack_a)->index != index)
	{
		if ((i > (size - 1) / 2))
			while ((*stack_a)->index != index && !is_sorted(stack_a, 0))
				ft_rev_rotate(stack_a, 'a');
		else
			while ((*stack_a)->index != index && !is_sorted(stack_a, 0))
				ft_rotate(stack_a, 'a');
	}
}

int	insert_sort(t_node **stack_a, t_node **stack_b, int max_i)
{
	int	i;
	int	index;

	if ((*stack_b && !*stack_a) || is_sorted(stack_a, 0))
		return (1);
	i = is_circular_sorted(stack_a, max_i);
	if (i)
		return (ft_lstalign(stack_a, 'a'));
	if (!*stack_b)
		index = 0;
	else
		index = (*stack_b)->index + 1;
	compute_exec_move(stack_a, index);
	if ((*stack_b && !*stack_a) || is_sorted(stack_a, 0))
		return (1);
	ft_push_b(stack_a, stack_b);
	return (0);
}
