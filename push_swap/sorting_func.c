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

int    insert_sort(node **a, node **b, int max_i)
{
	int			i;
	static int	*sorted_array;
	int 		size;
	node		*t;

	if (max_i <= -1)
		return 1;
	//ft_printf("max i = %d\n", max_i);
	//i = is_circular_sorted(a, max_i);
	//ft_printf("i = %d\n", i);
	size = ft_lstsize(a);
	sorted_array = 0;
	if (!sorted_array)
	{
		set_starting_point(a, size, 0, &sorted_array);
		while (ft_lstsize(a) != size - ft_arraylen(sorted_array) && ft_printf("size = %d asize = %d\n array len = %d",
																			  ft_lstsize(a), size - ft_arraylen(sorted_array),
																			  ft_arraylen(sorted_array)))
			check_is_in_array(a , b, sorted_array);
	}
	if (!*b)
		return (ft_lstalign(a, 'a'));
	i = 0;
	t = (*a)->next;
	while (t != *a)
	{
		i++;
		if (((*b)->number > t->number && (*b)->prev->number < t->number) // in line
			|| ((*b)->number < t->number
				&& (*b)->index == gmini(a, ft_lstsize(b), max_i)) //
			|| ((*b)->number < t->number && (*b)->prev->number < t->number
				&& (*b)->prev->index == gmi_in_s(b, ft_lstsize(b))))
			break ;
		t = t->next;
	}
	size = ft_lstsize(a);
	if ((i > (size - 1) / 2))
		while (i > 0 && !is_sorted(a, 0))
		{
			ft_rev_rotate(a, 'a');
			i--;
		}
	else
		while (i > 0 && !is_sorted(a, 0))
		{
			ft_rotate(a, 'a');
			i--;
		}
	ft_push_a(a, b);
	if (!*b)
		return (1);
	return (0);
}
