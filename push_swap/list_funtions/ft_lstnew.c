/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:32:01 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/04 15:20:42 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstnew(int num, node **head)
{
	node	*n;

	n = (node *)malloc(sizeof(node));
	if (!n)
		return ;
	if (!*head)
	{
		ft_printf("start not inicialized\n");
		*head = n;
		n->index = 0;
		n->prev = n;
	}
	else
	{
		n->prev = (*head)->prev;
		n->prev->next = n;
		(*head)->prev = n;
		n->index = n->prev->index + 1;
	}
	n->next = (*head);
	n->number = num;
}
