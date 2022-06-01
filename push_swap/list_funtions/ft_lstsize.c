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

	temp = start->next;
	size = 1;
	while (temp != start)
	{
		size++;
		ft_printf("index = %d\n", temp->prev->index);
		temp = temp->next;
	}
	ft_printf("index = %d\n", temp->prev->index);
	return (size);
}
