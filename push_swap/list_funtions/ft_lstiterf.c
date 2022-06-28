/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiterf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:30:42 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/02 15:30:47 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_node(node *stack)
{
	ft_printf("NUMBER = %d, 	INDEX = %d\n", stack->number, stack->index);
}

void	ft_lstiterf(node **stack, void (*f)())
{
	node	*temp;
	node	*ktemp;

	if (!*stack)
		return ;
	if (*stack)
		f(*stack);
	temp = (*stack)->next;
	while (temp != *stack)
	{
		ktemp = temp->next;
		f(temp);
		temp = ktemp;
		ktemp = 0;
	}
}
