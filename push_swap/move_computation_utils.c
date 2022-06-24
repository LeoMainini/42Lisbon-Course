/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_computation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:56:20 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/24 16:56:21 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gmini(node **a, int size, int max_i)
{
	int		i;
	int		min_index;
	node	*temp;

	temp = *a;
	min_index = max_i;
	i = -1;
	while (++i < size)
	{
		if (temp->index < min_index)
			min_index = temp->index;
		temp = temp->next;
	}
	return (min_index);
}

int	gmi_in_s(node **a, int size)
{
	int		i;
	int		max_index;
	node	*temp;

	temp = *a;
	max_index = 0;
	i = -1;
	while (++i <= size)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	return (max_index);
}

int	get_scaled_iterator(int counter, int size)
{
	if (counter > (size + 1) / 2)
		return (-((size + 1) - counter + 1));
	return (counter);
}

int	get_distance(int i, int k, int size, int asize)
{
	int	distance;
	int	ai;
	int	bi;

	bi = get_scaled_iterator(i, size);
	ai = get_scaled_iterator(k, asize);
	distance = 0;
	if (ai < 0)
		ai = -1 * (ai);
	if (bi < 0)
		bi = -1 * (bi);
	distance = ai + bi;
	return (distance);
}

void	compare_distance(int i, int k, moves *move_set, ps *s)
{
	int	size;
	int	asize;

	size = ft_lstsize(s->b);
	asize = ft_lstsize(s->a);
	if (get_distance(i, k, size, asize) < get_distance(
			move_set->b_moves, move_set->a_moves, size, asize))
	{
		move_set->target_a = s->t;
		move_set->target_b = s->bt;
		move_set->b_moves = get_scaled_iterator(i, size);
		move_set->a_moves = get_scaled_iterator(k, asize);
	}
}
