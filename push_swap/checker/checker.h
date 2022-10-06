/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:01:47 by leferrei          #+#    #+#             */
/*   Updated: 2022/10/06 12:01:48 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"

typedef struct stack_node{
	int					number;
	int					index;
	struct stack_node	*prev;
	struct stack_node	*next;
}	t_node;

typedef struct sort_moves{
	int		a_moves;
	int		b_moves;
	t_node	*target_a;
	t_node	*target_b;
}	t_moves;

typedef struct stacks {
	t_node	**a;
	t_node	**b;
	t_node	*t;
	t_node	*bt;
}	t_ps;

int		get_and_check_stack(int argc, char **argv, t_node **a, int null);
void	ft_swap_one(t_node **stack);
void	swap_both(t_node **stack_a, t_node **stack_b);
void	ft_rotate(t_node **stack);
void	ft_rotate_both(t_node **stack_a, t_node **stack_b);
void	ft_rev_rotate(t_node **stack);
void	ft_rev_rotate_both(t_node **stack_a, t_node **stack_b);
void	ft_push_a(t_node **a, t_node **b);
void	ft_push_b(t_node **a, t_node **b);
void	ft_swap(int *a, int *b);
long	check_input(char *nums);
int		check_duplicates_and_index(t_node *stack);
void	ft_lstiterf(t_node **stack, void (*f)());
int		ft_lstsize(t_node **start);
void	ft_lstnew(int num, t_node **head);
long	check_input(char *nums);
int		check_duplicate(t_node *stack);
int		sort_indexes(t_node *stack);
int		check_duplicates_and_index(t_node *stack);
int		is_digit(char c);
long	ft_atol(char *nptr);
void	ft_swap(int *a, int *b);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c, int *null);
char	*ft_strstr(const char *haystack, const char *needle);
void	print_node(t_node *stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strfreedup(char *s);
void	exec_insts(char ***insts, t_node **a, t_node **b);
int		is_sorted(t_node **stack, int reverse);
char	**parse_stdin(void);

#endif