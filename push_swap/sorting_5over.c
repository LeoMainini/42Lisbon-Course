/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:43:37 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/05 15:43:39 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_is_in_array(t_node **a, t_node **b, int *array)
{
	int	i;

	i = -1;
	while (array[++i] || array[i + 1])
	{
		if ((*a)->number == array[i])
		{
			ft_rotate(a, 'a');
			return ;
		}
	}
	ft_push_b(a, b);
}

static void	init_list(int **sorted_array, t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = ft_lstsize(stack_a);
	set_starting_point(stack_a, size, 0, sorted_array);
	while (ft_lstsize(stack_a) != ft_arraylen(*sorted_array))
		check_is_in_array(stack_a, stack_b, *sorted_array);
}

static void	exec_move(t_moves *move_set, t_node **stack_a, t_node **stack_b)
{
	if (move_set->a_moves > 0 && move_set->b_moves > 0)
		while (*stack_a != move_set->target_a && *stack_b != move_set->target_b)
			ft_rotate_both(stack_a, stack_b);
	else if (move_set->a_moves < 0 && move_set->b_moves < 0)
		while (*stack_a != move_set->target_a && *stack_b != move_set->target_b)
			ft_rev_rotate_both(stack_a, stack_b);
	while (move_set->a_moves > 0 && *stack_a != move_set->target_a)
		ft_rotate(stack_a, 'a');
	while (move_set->a_moves < 0 && *stack_a != move_set->target_a)
		ft_rev_rotate(stack_a, 'a');
	while (move_set->b_moves > 0 && *stack_b != move_set->target_b && *stack_b)
		ft_rotate(stack_b, 'b');
	while (move_set->b_moves < 0 && *stack_b != move_set->target_b && *stack_b)
		ft_rev_rotate(stack_b, 'b');
	ft_push_a(stack_a, stack_b);
}

int	predictive_insert_sort(t_node **stack_a, t_node **stack_b, int max_i)
{
	static int	*sorted_array;
	t_moves		move_set;

	if ((is_sorted(stack_a, 0)
			|| is_circular_sorted(stack_a, max_i)) && !*stack_b)
		return (ft_lstalign(stack_a, 'a'));
	if (!sorted_array)
		init_list(&sorted_array, stack_a, stack_b);
	if ((!*stack_b && *stack_a))
		return (1);
	move_set.b_moves = ft_lstsize(stack_b);
	move_set.a_moves = ft_lstsize(stack_a);
	decide_move(stack_a, stack_b, &move_set, max_i);
	exec_move(&move_set, stack_a, stack_b);
	if (!*stack_b)
	{
		free(sorted_array);
		ft_lstalign(stack_a, 'a');
		return (1);
	}
	return (0);
}
