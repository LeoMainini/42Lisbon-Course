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

void    ft_push_a(node **a, node **b)
{
    node *temp;

    if (!*b)
        return ;
    temp = *b;
    (*b)->next->prev = (*b)->prev;
    (*b)->prev->next = (*b)->next;
    *b = (*b) ->next;
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
        (*a)->prev = temp;
        temp->next = (*a);
    }
    ft_printf("pa\n");
}

void    ft_push_b(node **a, node **b)
{
    node *temp;

    if (!*a)
        return ;
    temp = *a;
    (*a)->next->prev = (*a)->prev;
    (*a)->prev->next = (*a)->next;
    *a = (*a)->next;
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
        (*b)->prev = temp;
        temp->next = (*b);
    }
    ft_printf("pb\n");
}