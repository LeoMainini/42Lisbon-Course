/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:15:33 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/02 22:01:08 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_lstalign(t_node **stack_a)
{
	int		size;
	int		i;
	t_node	*temp;

	temp = *stack_a;
	size = ft_lstsize(stack_a);
	i = 0;
	while (temp->index != 0)
	{
		i++;
		temp = temp->next;
	}
	if (i > size / 2)
		while ((*stack_a)->index != 0)
			ft_rev_rotate(stack_a);
	else
		while ((*stack_a)->index != 0)
			ft_rotate(stack_a);
	return (1);
}

void	ft_rotate(t_node **stack)
{
	*stack = (*stack)->next;
}

void	ft_rotate_both(t_node **stack_a, t_node **stack_b)
{
	if (!*stack_a || !*stack_b)
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_rev_rotate(t_node **stack)
{
	*stack = (*stack)->prev;
}

void	ft_rev_rotate_both(t_node **stack_a, t_node **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
}
