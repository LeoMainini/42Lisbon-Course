/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:51:54 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/24 16:51:56 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*area;
	size_t	i;

	area = (char *)malloc((count * size) * sizeof(*area));
	if (area == NULL)
		return (NULL);
	i = -1;
	while (++i < count * size)
		area[i] = 0;
	return (&area[0]);
}

int	ft_arraylen(int *array)
{
	int	i;

	i = 0;
	while ((array[i] || array[i + 1]))
		i++;
	return (i);
}

void	iterate_stack_for_sp(node *temp, int size, int k, int **best_array)
{
	int	*array;
	int	i;
	int	j;

	array = ft_calloc(size + 1, sizeof(int));
	while (k < size)
	{
		array[0] = temp->number;
		j = 0;
		i = 0;
		while (i < size)
		{
			if (temp->number > array[j])
				array[++j] = temp->number;
			temp = temp->next;
			i++;
		}
		if (ft_arraylen(array) > ft_arraylen(*best_array))
			ft_memmove(*best_array, array, (size + 1) * sizeof(int));
		ft_bzero(array, (size + 1) * sizeof(int));
		temp = temp->next;
		k++;
	}
	free(array);
}

void	set_starting_point(node **a, int size, int k, int **best_array)
{
	node	*temp;

	if (!*a)
		return ;
	temp = *a;
	*best_array = ft_calloc(size + 1, sizeof(int));
	iterate_stack_for_sp(temp, size, k, best_array);
}
