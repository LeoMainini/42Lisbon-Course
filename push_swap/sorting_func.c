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

void check_decrement_index(node *stack)
{
	int		found_zero;
	node	*temp;

	found_zero = 0;
	temp = (stack)->next;
	if (temp->prev->index == 0)
		found_zero = 1;
	while (temp != stack)
	{

		if (temp->index == 0)
			found_zero = 1;
		temp = temp->next;
	}
	if (!found_zero)
	{
		temp->index -= 1;
		temp = temp->next;
		while (temp != stack)
		{
			temp->index -= 1;
			temp = temp->next;
		}
	}

}

int get_size_sort_index(node *stack)
{
	int size;

	if (!stack)
		return (0);
	size = ft_lstsize(&stack);
	return (size);
}

int is_sorted(node **stack, int reverse)
{
	node *temp;

	if (!*stack)
		return 0;
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

int is_circular_sorted(node **stack, int max_i)
{
	int		i;
	int 	k;
	node	*temp;

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
/*
int    insert_sort(node **stack_a, node **stack_b, int max_i)
{
	int	i;
	int size;
	int index;
	node *temp;

	if ((*stack_b && !*stack_a) || is_sorted(stack_a, 0))
		return (1);
	//ft_printf("max i = %d\n", max_i);
	i = is_circular_sorted(stack_a, max_i);
	//ft_printf("i = %d\n", i);
	if (i)
		return (ft_lstalign(stack_a, 'a'));
	if (!*stack_b)
		index = 0;
	else
		index = (*stack_b)->index + 1;
	sort_indexes(*stack_a);
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
		size = ft_lstsize(stack_a);
		if ((i > (size - 1) / 2))
			while ((*stack_a)->index != index && !is_sorted(stack_a, 0))
				ft_rev_rotate(stack_a, 'a');
		else
			while ((*stack_a)->index != index && !is_sorted(stack_a, 0))
				ft_rotate(stack_a, 'a');
	}
	if ((*stack_b && !*stack_a) || is_sorted(stack_a, 0))
		return (1);
	ft_push_b(stack_a, stack_b);
	return (0);
}
*/
