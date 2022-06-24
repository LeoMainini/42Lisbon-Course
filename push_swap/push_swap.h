/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swapper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:38:20 by leferrei          #+#    #+#             */
/*   Updated: 2022/05/30 16:38:22 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "ft_printf/ft_printf.h"

typedef struct stack_node{
	int					number;
	int					index;
	struct stack_node	*prev;
	struct stack_node	*next;
}	node;

typedef struct sort_moves{
	int		a_moves;
	int		b_moves;
	node	*target_a;
	node	*target_b;
}	moves;

typedef struct stacks {
	node	**a;
	node	**b;
	node	*t;
	node	*bt;
}	ps;

int		gmini(node **a, int size, int max_i);
int		gmi_in_s(node **a, int size);
void	check_is_in_array(node **a, node **b, int *array);
int		ft_arraylen(int *array);
void	set_starting_point(node **a, int size, int k, int **best_array);
int		predictive_insert_sort(node **stack_a, node **stack_b, int max_i);
int		is_circular_sorted(node **stack, int max_i);
void	sortStack(node **a, node **b);
void	sort_stack_insert_recursive(node **a, node **b);
int		insert_sort(node **a, node **b, int max_i);
int		ft_lstalign(node **stack_a, char c);
void	print_node(node *stack);
void	push_all_a(node **a, node **b);
int		push_all_b(node **a, node **b);
int		is_sorted(node **stack, int reverse);
int		sort_indexes(node *stack);
int		is_digit(char c);
long	check_input(char *nums);
int		check_duplicates_and_index(node *stack);
void	ft_lstiterf(node **stack, void (*f)());
int		ft_lstsize(node **start);
void	ft_lstnew(int num, node **head);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c, int *null);
long	ft_atol(char *nptr);
void	ft_swap_one(node **stack, char c);
void	swap_both(node **stack_a, node **stack_b);
void	ft_rotate(node **stack, char c);
void	ft_rotate_both(node **stack_a, node **stack_b);
void	ft_rev_rotate(node **stack, char c);
void	ft_rev_rotate_both(node **stack_a, node **stack_b);
void	ft_push_a(node **a, node **b);
void	ft_push_b(node **a, node **b);
void	ft_swap(int *a, int *b);
int		sort_3(node **a, int max_i);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_arraylen(int *array);
void	iterate_stack_for_sp(node *temp, int size, int k, int **best_array);
void	set_starting_point(node **a, int size, int k, int **best_array);
void	decide_move(node **a, node **b, moves *move_set, int max_i);
int		gmini(node **a, int size, int max_i);
int		gmi_in_s(node **a, int size);
int		get_scaled_iterator(int counter, int size);
int		get_distance(int i, int k, int size, int asize);
void	compare_distance(int i, int k, moves *move_set, ps *s);

#endif