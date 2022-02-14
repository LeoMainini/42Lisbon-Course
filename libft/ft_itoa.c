/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:00:32 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/14 21:23:01 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*clean_output(char *temp, int neg, int i)
{
	int		j;
	int		size;
	char	*result;

	j = 0;
	size = 11 - i + neg - 1;
	i = 10;
	result = (char *)malloc(size * sizeof(*result));
	while (temp[i] != '\0')
	{
		result[size - 1] = temp [i];
		size--;
		i--;
	}
	return (&result[0]);
}

void	clean_temp(char *temp)
{
	int	i;

	i = -1;
	while (++i < 10)
		temp[i] = '\0';
}

char	*ft_itoa(int n)
{
	long	n_l;
	char	temp[11];
	int		i;
	int		neg;

	clean_temp(temp);
	i = 10;
	n_l = (long)n;
	neg = 0;
	if (n_l < 0)
	{
		neg = 1;
		n_l = -n_l;
	}
	if (n_l == 0)
		return (clean_output("01234567890", 0, 9));
	while (n_l != 0 && i >= 0)
	{
		temp[i] = "0123456789"[n_l % 10];
		i--;
		n_l = n_l / 10;
	}
	if (neg == 1)
		temp[i] = '-';
	return (clean_output(temp, neg, i));
}

int main(void)
{
	printf("555 = %s\n", ft_itoa(555));
	printf("-555 = %s\n", ft_itoa(-555));
	printf("10 = %s\n", ft_itoa(10));
	printf("223423423 = %s\n", ft_itoa(223423423 ));
	printf("-2,147,483,648 = %s\n", ft_itoa(-2147483648));
	printf("1 = %s\n", ft_itoa(1));
	printf("-1 = %s\n", ft_itoa(-1));
	printf("0 = %s\n", ft_itoa(0));
}








