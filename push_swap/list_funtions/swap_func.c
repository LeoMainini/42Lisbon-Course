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

#include "../push_swap.h"

void	ft_swap_one(node **stack, char c)
{
	node	*temp;
	node	*ktemp;

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
	if (c != 's')
		ft_printf("s%c\n", c);
}

void	swap_both(node **stack_a, node **stack_b)
{
	ft_swap_one(stack_a, 's');
	ft_swap_one(stack_b, 's');
	ft_printf("ss\n");
}
