/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:02:48 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/17 13:18:51 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}
