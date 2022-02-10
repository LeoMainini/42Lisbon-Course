/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:51:00 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/10 12:02:04 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
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


int main(void)
{
	printf("%d\n", atoi("123"));
	printf("%d\n", atoi(" -123"));
	printf("%d\n", atoi(" --123"));
	printf("%d\n", atoi(" 	+123"));
	printf("%d\n", atoi("   	123"));
	printf("%d\n", ft_atoi("123"));
	printf("%d\n", ft_atoi(" -123"));
	printf("%d\n", ft_atoi(" --123"));
	printf("%d\n", ft_atoi(" 	+123"));
	printf("%d\n", ft_atoi("   	123"));

}
