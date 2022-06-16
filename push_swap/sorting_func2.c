/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:43:37 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/05 15:43:39 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string.h"
/*
int is_circular_sorted(node **stack, int max_i)
{
	int		i;
	int 	k;
	node	*temp;

	temp = *stack;
	i = 0;
	k = 1;
	while (temp->index < temp->next->index && temp->index != max_i)
	{
		temp = temp->next;
		k++;
	}
	temp = temp->next;
	while (temp->index < temp->next->index)
	{
		temp = temp->next;
		i++;
	}
	if (max_i == i)
		return (k);
	return (0);
}
*/

int gmini(node **a, int size, int max_i)
{
	int		i;
	int 	min_index;
	node	*temp;

	temp = *a;
	min_index = max_i;
	i = -1;
	while (++i < size)
	{
		if (temp->index < min_index)
			min_index = temp->index;
		temp = temp->next;
	}
	return (min_index);
}

int gmi_in_s(node **a, int size)
{
	int		i;
	int 	max_index;
	node	*temp;

	temp = *a;
	max_index = 0;
	i = -1;
	while (++i <= size)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	return (max_index);
}

int get_scaled_iterator(int counter, int size)
{
	if (counter > (size + 1) / 2)
		return (-((size + 1) - counter + 1));
	return (counter);
}
int get_distance(int i, int k, int size, int asize)
{
	int distance;
	int ai;
	int bi;

	bi = get_scaled_iterator(i, size);
	ai = get_scaled_iterator(k, asize);

	distance = 0;
	if (ai < 0)
		ai = -1 * (ai);
	if (bi < 0)
		bi = -1 * (bi);
	distance = ai + bi;
	return (distance);
}

void	decide_move(node **a, node **b, moves *move_set, int max_i)
{
	int i;
	int k;
	int size;
	int asize;
	node *t;
	node *bt;

	t = *a;
	bt = *b;
	size = ft_lstsize(b);
	asize = ft_lstsize(a);
	move_set->a_moves = asize;
	move_set->b_moves = size;
	i = 0;
	if (!max_i)
		return ;
	while (i < size)
	{
		k = 0;
		//if (i++ < (size * 0.25) || i++ > (0.75 * size))
		//	continue ;
		while(k < asize)
		{
			//if (!(k++ < (asize * 0.25) || k++ > (0.75 * asize)))
			//	continue ;
			//borks algorythm when it cant find a shorter path than the current pushed cell
			//since it keeps rotating to find it

			if (((t->number > bt->number && t->prev->number < bt->number) // in line
				|| (t->number > bt->number
					&& t->index == gmini(a, asize, max_i)) //
				|| (t->number < bt->number && t->prev->number < bt->number
					&& t->prev->index == gmi_in_s(a, asize))))
			{

				if (get_distance(i , k, size, asize) < move_set->a_moves + move_set->b_moves)
				{

					move_set->target_a = t;
					move_set->target_b = bt;
					move_set->b_moves = get_scaled_iterator(i, size);
					move_set->a_moves = get_scaled_iterator(k, asize);
					//ft_printf("ai = %d, bi = %d\n", move_set->a_moves, move_set->b_moves);
				}
				/*
				if (k + i < move_set->a_moves + move_set->b_moves)
				{
					move_set->a_moves = k;
					move_set->b_moves = i;
				}*/
			}
			k++;
			t = t->next;
		}
		i++;
		bt = bt->next;
	}
}

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

int ft_arraylen(int *array)
{
	int	i;

	i = 0;
	while ((array[i] || array[i + 1]))
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest == NULL && src == NULL)
		return (0);
	if (dest > src)
	{
		i = (int)n;
		while (--i >= 0)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		i = -1;
		while (++i < (int)n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}
void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	**str;

	str = (char **)&s;
	index = 0;
	while (index < n)
	{
		(*str)[index] = '\0';
		index++;
	}
}

void	set_starting_point(node **a, int size, int k, int **best_array)
{
	int		*array;
	node	*temp;
	int		j;
	int		i;

	if (!*a)
		return ;
	temp = *a;
	array = ft_calloc(size + 1, sizeof(int));
	*best_array = ft_calloc(size + 1, sizeof(int));
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
		//printf("array len = %d\t\tbest_array len = %d\n",ft_arraylen(array), ft_arraylen(*best_array));
		if (ft_arraylen(array) > ft_arraylen(*best_array))
			ft_memmove(*best_array, array, (size + 1) * sizeof(int));
		ft_bzero(array, (size + 1) * sizeof(int));
		temp = temp->next;
		k++;
	}
	free(array);
}

void	check_is_in_array(node **a, node **b, int *array)
{
	int i;

	i = -1;
	while (array[++i] || array[i + 1])
	{
		if ((*a)->number == array[i]) // changed for insert is == in predictive
		{
			ft_rotate(a, 'a');
			return ;
		}
	}
	ft_push_b(a , b);
}

int    predictive_insert_sort(node **stack_a, node **stack_b, int max_i)
{
	int size;
	static int	*sorted_array;
	moves move_set;

	if (max_i <= -1)
		return 1;
	size = ft_lstsize(stack_a);
	if (!sorted_array)
	{
		set_starting_point(stack_a, size, 0, &sorted_array);
		while (ft_lstsize(stack_a) != ft_arraylen(sorted_array))
			check_is_in_array(stack_a , stack_b, sorted_array);
	}
	if ((!*stack_b && *stack_a))
		return (1);
	move_set.b_moves = ft_lstsize(stack_b);
	move_set.a_moves = ft_lstsize(stack_a);
	decide_move(stack_a , stack_b, &move_set, max_i);
	if (move_set.a_moves > 0 && move_set.b_moves > 0)
		while (move_set.a_moves != 0 && move_set.b_moves != 0
			&& *stack_a != move_set.target_a && *stack_b != move_set.target_b)
			ft_rotate_both(stack_a , stack_b);
	else if (move_set.a_moves < 0 && move_set.b_moves < 0)
		while (move_set.a_moves != 0 && move_set.b_moves != 0
			&& *stack_a != move_set.target_a && *stack_b != move_set.target_b)
			ft_rev_rotate_both(stack_a , stack_b);
	while (move_set.a_moves > 0 && *stack_a != move_set.target_a)
		ft_rotate(stack_a, 'a');
	while (move_set.a_moves < 0 && *stack_a != move_set.target_a)
		ft_rev_rotate(stack_a, 'a');
	while (move_set.b_moves > 0 && *stack_b != move_set.target_b && *stack_b)
		ft_rotate(stack_b, 'b');
	while (move_set.b_moves < 0 && *stack_b != move_set.target_b && *stack_b)
		ft_rev_rotate(stack_b, 'b');
	ft_push_a(stack_a, stack_b);
	if (!*stack_b)
	{
		free(sorted_array);
		ft_lstalign(stack_a, 'a');
		return (1);
	}
	return (0);
}