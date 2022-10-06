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

#include "../checker.h"

void	print_node(t_node *stack)
{
	ft_printf("NUMBER = %d, 	INDEX = %d\n", stack->number, stack->index);
}

void	ft_lstiterf(t_node **stack, void (*f)())
{
	t_node	*temp;
	t_node	*ktemp;

	if (!*stack)
		return ;
	temp = (*stack)->next;
	while (temp != *stack)
	{
		ktemp = temp->next;
		f(temp);
		temp = ktemp;
		ktemp = 0;
	}
	if (*stack)
		f(*stack);
}
