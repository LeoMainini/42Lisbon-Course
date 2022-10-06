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

#include "../checker.h"

void	ft_lstnew(int num, t_node **head)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return ;
	if (!*head)
	{
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
