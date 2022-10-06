/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:15:19 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/02 22:01:15 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	check_link(t_node **stack)
{
	if (*stack == (*stack)->next)
		*stack = 0;
	else
		*stack = (*stack)->next;
}

void	ft_push_a(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*b)
		return ;
	temp = *b;
	(*b)->next->prev = (*b)->prev;
	(*b)->prev->next = (*b)->next;
	check_link(b);
	if (!*a)
	{
		*a = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		(*a)->prev->next = temp;
		temp->prev = (*a)->prev;
		temp->next = (*a);
		(*a)->prev = temp;
		*a = temp;
	}
}

void	ft_push_b(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*a)
		return ;
	temp = *a;
	(*a)->next->prev = (*a)->prev;
	(*a)->prev->next = (*a)->next;
	check_link(a);
	if (!*b)
	{
		*b = temp;
		temp->next = temp;
		temp->prev = temp;
	}
	else
	{
		(*b)->prev->next = temp;
		temp->prev = (*b)->prev;
		temp->next = (*b);
		(*b)->prev = temp;
		*b = temp;
	}
}

void	push_all_a(t_node **a, t_node **b)
{
	while (*b)
		ft_push_a(a, b);
}

int	push_all_b(t_node **a, t_node **b)
{
	while (*a)
		ft_push_b(a, b);
	return (1);
}
