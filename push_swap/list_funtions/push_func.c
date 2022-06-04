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

#include "../push_swap.h"
void check_link(node **stack)
{
	if (*stack == (*stack)->next)
		*stack = 0;
	else
		*stack = (*stack)->next;
}
void    ft_push_a(node **a, node **b)
{
	node *temp;

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
	ft_printf("pb\n");
}

void    ft_push_b(node **a, node **b)
{
    node *temp;

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
    ft_printf("pb\n");
}

void	push_all(node **from, node **to)
{
	while (*from)
		ft_push_a(from, to);
}