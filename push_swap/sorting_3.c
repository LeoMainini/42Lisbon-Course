/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:38:18 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/23 16:38:20 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3(t_node **a, int max_i)
{
	if (is_sorted(a, 0) || is_circular_sorted(a, max_i))
		return (ft_lstalign(a, 'a'));
	if ((*a)->index == 1 && (*a)->next->index == 0)
		ft_swap_one(a, 'a');
	if ((*a)->index == 0 && (*a)->next->index == 2)
	{
		ft_swap_one(a, 'a');
		ft_rotate(a, 'a');
	}
	if ((*a)->index == 2 && (*a)->next->index == 1)
	{
		ft_rotate(a, 'a');
		ft_swap_one(a, 'a');
	}
	return (1);
}
