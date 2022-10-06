/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:25:27 by leferrei          #+#    #+#             */
/*   Updated: 2022/10/06 12:25:36 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strfreedup(char *s)
{
	int		i;
	char	*res;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	i = -1;
	while (s[++i] != 0)
		res[i] = s[i];
	res[i] = 0;
	free(s);
	return (res);
}

static void	exec_inst(char *s, t_node **a, t_node **b)
{
	if (!ft_strncmp(s, "sa\n", 3))
		ft_swap_one(a);
	if (!ft_strncmp(s, "sb\n", 3))
		ft_swap_one(b);
	if (!ft_strncmp(s, "ss\n", 3))
		swap_both(a, b);
	if (!ft_strncmp(s, "ra\n", 3))
		ft_rotate(a);
	if (!ft_strncmp(s, "rb\n", 3))
		ft_rotate(b);
	if (!ft_strncmp(s, "rr\n", 3))
		ft_rotate_both(a, b);
	if (!ft_strncmp(s, "pa\n", 3))
		ft_push_a(a, b);
	if (!ft_strncmp(s, "pb\n", 3))
		ft_push_b(a, b);
	if (!ft_strncmp(s, "rra\n", 4))
		ft_rev_rotate(a);
	if (!ft_strncmp(s, "rrb\n", 4))
		ft_rev_rotate(b);
	if (!ft_strncmp(s, "rrr\n", 4))
		ft_rev_rotate_both(a, b);
}

void	exec_insts(char ***insts, t_node **a, t_node **b)
{
	int	i;

	i = -1;
	while ((*insts)[++i])
		exec_inst((*insts)[i], a, b);
}

int	is_sorted(t_node **stack, int reverse)
{
	t_node	*temp;

	if (!*stack)
		return (0);
	temp = (*stack);
	while (!reverse && temp != (*stack)->prev)
	{
		if (temp->next->number < temp->number)
			return (0);
		temp = temp->next;
	}
	while (reverse && temp != (*stack)->prev)
	{
		if (temp->next->number > temp->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

char	**parse_stdin(void)
{
	char	**inst;
	char	**temp;
	int		k;
	int		i;

	inst = (char **) malloc(2 * sizeof(char *));
	inst[1] = 0;
	k = 0;
	inst[k] = get_next_line(STDIN_FILENO);
	while (inst[k++])
	{
		inst[k] = ft_strfreedup(get_next_line(STDIN_FILENO));
		temp = (char **) malloc((k + 2) * sizeof(char *));
		i = -1;
		while (++i <= k)
			temp[i] = ft_strfreedup(inst[i]);
		temp[i] = 0;
		free(inst);
		inst = (char **) malloc((k + 3) * sizeof(char *));
		i = -1;
		while (++i <= k)
			inst[i] = ft_strfreedup(temp[i]);
		free(temp);
	}
	return (inst);
}
