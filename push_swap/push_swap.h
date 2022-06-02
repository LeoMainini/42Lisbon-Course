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
	int		number;
	int		index;
	struct stack_node	*prev;
	struct stack_node	*next;
}	node;

typedef struct stack{
	node	*start;
	node	*end;
	int		size;
}	stack;

typedef struct stacks{
	stack 	*a;
	stack 	*b;
}	ps;

int		is_digit(char c);
long	check_input(char *nums);
int		check_duplicates_and_index(node *stack);
void	ft_lstiterf(node **stack, void(*f)());
int		ft_lstsize(node *start);
void	ft_lstnew(int num, node **head);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
long	ft_atol(char *nptr);

#endif