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

void check_decrement_index(node **stack)
{
	int		found_zero;
	node	*temp;

	found_zero = 0;
	temp = (*stack)->next;
	if (temp->prev->index == 0)
		found_zero = 1;
	while (temp != *stack)
	{

		if (temp->index == 0)
			found_zero = 1;
		temp = temp->next;
	}
	if (!found_zero)
	{
		temp->index -= 1;
		temp = temp->next;
		while (temp != *stack)
		{
			temp->index -= 1;
			temp = temp->next;
		}
	}

}

int get_size_sort_index(node **stack)
{
	int size;

	if (!*stack)
		return (0);
	sort_indexes(*stack);
	sort_indexes((*stack)->prev);
	check_decrement_index(stack);
	size = ft_lstsize(*stack);
	ft_printf("size = %d\n", size);
	return (size);
}

int is_sorted(node **stack)
{
	node *temp;

	if (!*stack)
		return 0;
	temp = (*stack);
	while (temp != (*stack)->prev)
	{
		if (temp->next->number < temp->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int    insert_sort(node **stack_a, node **stack_b)
{
	int	i;
	int size;
	node *temp;

	//ft_printf("got here\n");
	if (*stack_b && !*stack_a)
		return (1);
	size = get_size_sort_index(stack_a);
	i = 0;
	temp = (*stack_a)->next;
	while (temp != *stack_a)
	{
		i++;
		if (temp->index == 0) {
			break ;
		}
		temp = temp->next;
	}
	ft_printf("SIZE = %d, I = %d\n", size, i);

	if ((*stack_a)->index == 0)
		ft_push_b(stack_a, stack_b);
	else
	{
		size = get_size_sort_index(stack_a);
		if (i > size / 2)
			while ((*stack_a)->index != 0)
				ft_rev_rotate(stack_a, 'a');
		else
			while ((*stack_a)->index != 0)
				ft_rotate(stack_a, 'a');
	}
	size = get_size_sort_index(stack_a);

	ft_push_b(stack_a, stack_b);

	size = get_size_sort_index(stack_b);

	return (0);
}

