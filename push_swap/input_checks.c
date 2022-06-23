/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:17:07 by leferrei          #+#    #+#             */
/*   Updated: 2022/06/02 16:17:09 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(char *nptr)
{
	int		i;
	int		neg;
	long	result;

	i = 0;
	neg = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + nptr[i] - 48;
		i++;
	}
	return (result * neg);
}

long	check_input(char *nums)
{
	long	num;
	int		i;

	i = 0;
	if (nums[i] == '-' || nums[i] == '+')
		i++;
	while (is_digit(nums[i]))
		i++;
	if (nums[i] != '\0' || i > 11 || (i > 0 && !is_digit(nums[i - 1])))
		return (-4000000000);
	num = ft_atol(nums);
	if (num > 2147483647 || num < -2147483648)
		return (-4000000000);
	return (num);
}


int check_duplicate(node *stack)
{
	int size;
	int i;
	int k;
	node *temp;
	node *ktemp;

	if (!stack)
		return (1);
	temp = stack;
	size = ft_lstsize(&stack);
	i = -1;
	while (++i < size)
	{
		k = 0;
		ktemp = temp->next;
		while (++k < size)
		{
			if (ktemp->number == temp->number)
				return (1);
			ktemp = ktemp->next;
		}
		temp = temp->next;
	}
	return (0);
}

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

int sort_indexes(node *stack)
{
	int		i;
	int 	k;
	node	*temp;
	node	*ktemp;
	int		max_index;

	max_index = 0;
	i = ft_lstsize(&stack);
	k = ft_lstsize(&stack);
	temp = stack;
	while (k > 0)
	{
		ktemp = temp->next;
		while (i > 0)
		{
			if (temp->index > max_index)
				max_index = temp->index;
			if ((ktemp->number > temp->number && ktemp->index < temp->index)
				|| (ktemp->number < temp->number && ktemp->index > temp->index))
				ft_swap(&ktemp->index, &temp->index);
			temp = temp->next;
			i--;
		}
		i = ft_lstsize(&stack);
		temp = temp->next;
		k--;
	}
	return (max_index);
}

int	check_duplicates_and_index(node *stack)
{
	int max_index;
	int temp;

	if (!stack)
		return (0);
	temp = sort_indexes(stack);
	max_index = sort_indexes(stack->prev);
	if (temp == -1 || max_index == -1 || check_duplicate(stack))
		return (-1);
	if (temp > max_index)
		max_index = temp;
	return (max_index);
}
