/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:15:11 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/02 21:15:14 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_swap_one(t_node **stack)
{
	t_node	*temp;
	t_node	*ktemp;

	if (!(*stack) || (*stack)->next == (*stack))
		return ;
	temp = *stack;
	ktemp = (*stack)->next;
	ktemp->next->prev = temp;
	temp->prev->next = ktemp;
	temp->next = ktemp->next;
	ktemp->next = temp;
	ktemp->prev = temp->prev;
	temp->prev = ktemp;
	(*stack) = ktemp;
}

void	swap_both(t_node **stack_a, t_node **stack_b)
{
	ft_swap_one(stack_a);
	ft_swap_one(stack_b);
}
