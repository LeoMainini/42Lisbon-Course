/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:20:11 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/24 18:25:42 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
int	ft_lstsize(node *start)
{
	int	size;
	node *temp;

	if (!start)
		return (0);
	temp = start->next;
	size = 0;
	while ( temp && temp != start)
	{
		size++;
		//ft_printf("num = %d\t\t|	index = %d\n", temp->prev->number, temp->prev->index);
		temp = temp->next;
	}
	if (temp)
	{
		size++;
		//ft_printf("num = %d\t\t|	index = %d\n", temp->prev->number, temp->prev->index);
	}
	return (size);
}
