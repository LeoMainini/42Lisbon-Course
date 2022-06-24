/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_computation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:55:20 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/24 16:55:22 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_target(ps *s, int max_i, int asize)
{
	return (((s->t->number > s->bt->number && s->t->prev->number
				< s->bt->number) || (s->t->number > s->bt->number
				&& s->t->index == gmini(s->a, asize, max_i))
			|| (s->t->number < s->bt->number && s->t->prev->number
				< s->bt->number
				&& s->t->prev->index == gmi_in_s(s->a, asize))));
}

void	compute_best_move(ps *s, moves	*move_set, int max_i)
{
	int	i;
	int	k;
	int	size;
	int	asize;

	size = ft_lstsize(s->b);
	asize = ft_lstsize(s->a);
	i = -1;
	if (!max_i)
		return ;
	while (++i < size)
	{
		k = -1;
		while (++k < asize)
		{
			if (is_valid_target(s, max_i, asize))
				compare_distance(i, k, move_set, s);
			s->t = s->t->next;
		}
		s->bt = s->bt->next;
	}
}

void	decide_move(node **a, node **b, moves *move_set, int max_i)
{
	ps	stacks;

	stacks.a = a;
	stacks.b = b;
	stacks.t = *a;
	stacks.bt = *b;
	move_set->a_moves = ft_lstsize(a);
	move_set->b_moves = ft_lstsize(b);
	compute_best_move(&stacks, move_set, max_i);
}
