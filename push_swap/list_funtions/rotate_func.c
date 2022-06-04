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

#include "../push_swap.h"

int	ft_lstalign(node **stack_a, int i, char c)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (i > size / 2)
		while (i != size)
		{
			ft_rev_rotate(stack_a, c);
			i++;
		}
	else
		while (i > 0)
		{
			ft_rotate(stack_a, c);
			i--;
		}
	return (1);
}

void    ft_rotate(node **stack, char c)
{
    (*stack) = (*stack)->next;
    if (c != 'r')
        ft_printf("r%c\n", c);
}

void    ft_rotate_both(node **stack_a, node **stack_b)
{
    ft_rotate(stack_a, 'r');
    ft_rotate(stack_b, 'r');
    ft_printf("rr\n");
}

void    ft_rev_rotate(node **stack, char c)
{
    (*stack) = (*stack)->prev;
    if (c != 'r')
        ft_printf("rr%c\n", c);
}

void    ft_rev_rotate_both(node **stack_a, node **stack_b)
{
    ft_rev_rotate(stack_a, 'r');
    ft_rev_rotate(stack_b, 'r');
    ft_printf("rrr\n");
}
