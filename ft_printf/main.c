/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:36:23 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/15 17:23:28 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int	i;
	int	k;

	i = ft_printf("Ola o meu nome e %c %s %d %i %u %x %X %% %p\n", 'H', "Ola o meu nome e leo", 48, 48, 324234234, 21474836, 2147483647, NULL);
	k = printf("Ola o meu nome e %c %s %d %i %u %x %X %% %p\n", 'H', "Ola o meu nome e leo", 48, 48, 324234234, 21474836, 2147483647, NULL);
	ft_printf("i = %d\n", i);
	ft_printf("k = %d\n", k);
	i = ft_printf("\n");
	k = printf("\n");
	ft_printf("i = %d\n", i);
	ft_printf("k = %d\n", k);
}
