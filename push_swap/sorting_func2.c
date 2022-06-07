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
void	decide_move(node **a, node **b, moves *move_set)
{
	int i;
	int k;
	//int bi;
	//int ai;
	int size;
	int asize;
	node *temp;
	node *btemp;

	temp = *a;
	btemp = *b;
	size = ft_lstsize(b);
	asize = ft_lstsize(a);
	i = 0;
	while (i < size)
	{
		k = 0;

		while(k < asize)
		{
			//ai = k;
			//bi = i;
			if (temp->index == btemp->index + 1)
			{
				/*
				if (i > (size - 1) / 2)
					bi = -((size - 1) - i + 1);
				if (k > (asize - 1) / 2)
					ai = -((asize - 1) - k + 1);

				if (ai + bi < move_set->a_moves + move_set->b_moves)
				{
					move_set->a_moves = ai;
					move_set->b_moves = bi;
				}*/
				if (k + i < move_set->a_moves + move_set->b_moves)
				{
					move_set->a_moves = k;
					move_set->b_moves = i;
				}
			}
			k++;
			temp = temp->next;
		}
		i++;
		btemp = btemp->next;
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
	while (array[i] || array[i + 1])
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	**b_src;
	char	**b_dest;
	size_t	index;

	if (dest == NULL && src == NULL)
		return (dest);
	b_dest = (char **)&dest;
	b_src = (char **)&src;
	index = -1;
	while (++index < n)
		(*b_dest)[index] = (*b_src)[index];
	return (&((*b_dest)[0]));
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
 		array[0] = temp->index;
		j = 0;
		i = 0;
		while (i < size)
		{
			if (temp->index > array[j])
				array[++j] = temp->index;
			temp = temp->next;
			i++;
		}
		//printf("array len = %d\t\tbest_array len = %d\n",ft_arraylen(array), ft_arraylen(*best_array));
		if (ft_arraylen(array) > ft_arraylen(*best_array))
			ft_memmove(*best_array, array, size * sizeof(int));
		ft_bzero(array, size);
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
		if ((*a)->index == array[i])
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
	//int i;
	moves move_set;
	if (max_i < -1)
		return 1;
	//i = 0;
	//i = is_circular_sorted(stack_a, max_i);
	//if (i)
	//	return (ft_lstalign(stack_a, i, 'a'));
	size = ft_lstsize(stack_a);
	if (!sorted_array)
	{
		set_starting_point(stack_a, size, 0, &sorted_array);
		while (ft_lstsize(stack_a) != ft_arraylen(sorted_array))
			check_is_in_array(stack_a , stack_b, sorted_array);
	}
	//if (ft_arraylen(sorted_array) == 0)
	//	ft_lstalign(&stack_a, max_i, 'a');
	if ((!*stack_b && *stack_a))
		return (1);
	//ft_printf("STACK A\n");
	//ft_lstiterf(stack_a, &print_node);
	//ft_printf("STACK B\n");
	//ft_lstiterf(stack_b, &print_node);
	move_set.b_moves = ft_lstsize(stack_b);
	move_set.a_moves = ft_lstsize(stack_a);
	decide_move(stack_a , stack_b, &move_set);
	//ft_printf("A MOVES = %d\tB MOVES = %d\n", move_set.a_moves, move_set.b_moves);
	if (move_set.a_moves > 0 && move_set.b_moves > 0)
		while (move_set.a_moves != 0 && move_set.b_moves != 0)
		{
			ft_rotate_both(stack_a , stack_b);
			move_set.a_moves--;
			move_set.b_moves--;
		}
	else if (move_set.a_moves < 0 && move_set.b_moves < 0)
		while (move_set.a_moves != 0 && move_set.b_moves != 0)
		{
			ft_rev_rotate_both(stack_a , stack_b);
			move_set.a_moves++;
			move_set.b_moves++;
		}
	while (move_set.a_moves > 0)
	{
		ft_rotate(stack_a, 'a');
		move_set.a_moves--;
	}
	while (move_set.a_moves < 0)
	{
		ft_rev_rotate(stack_a, 'a');
		move_set.a_moves++;
	}
	while (move_set.b_moves > 0)
	{
		ft_rotate(stack_b, 'b');
		move_set.b_moves--;
	}
	while (move_set.b_moves < 0)
	{
		ft_rev_rotate(stack_b, 'b');
		move_set.b_moves++;
	}
	ft_push_a(stack_a, stack_b);
	//ft_printf("STACK A\n");
	//ft_lstiterf(stack_a, &print_node);
	//ft_printf("STACK B\n");
	//ft_lstiterf(stack_b, &print_node);

	if (!*stack_b)
	{
		free(sorted_array);
		ft_lstalign(stack_a, 'a');
	//	ft_printf("STACK A\n");
	//	ft_lstiterf(stack_a, &print_node);
	//	ft_printf("STACK B\n");
	//	ft_lstiterf(stack_b, &print_node);

		return (1);
	}
	return (0);
}