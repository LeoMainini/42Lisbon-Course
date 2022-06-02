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
