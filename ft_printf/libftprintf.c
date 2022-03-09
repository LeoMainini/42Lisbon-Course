/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:18:03 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/09 18:19:48 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

void	char_func(va_list value)
{
	char	c;

	c = (char)va_arg(value, int);
	ft_putchar_fd(c, 1);
}

void	str_func(va_list value)
{
	char	*s;

	s = (char *)va_arg(value, int *);
	ft_putstr_fd(s, 1);

}

void	pointer_func(va_list value)
{
	void	*s;
	s = (char *)va_arg(value, int *);

	printf("%p", s);
}

static int	check_type(char c, va_list value)
{
	if (c == 'c')
		char_func(value);
	else if (c == 's')
		str_func(value);
	else if (c == 'p')
		pointer_func(value);
	else if (c == 'd')
		ft_putstr_fd("digit", 1);
	else if (c == 'i')
		ft_putstr_fd("int", 1);
	else if (c == 'u')
		ft_putstr_fd("unsigned digit", 1);
	else if (c == 'x')
		ft_putstr_fd("small hex", 1);
	else if(c == 'X')
		ft_putstr_fd("Big HEX", 1);
	else if (c == '%')
		ft_putstr_fd("percent", 1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list value;
	//char	*temp;
	int		i;

	i = -1;
	va_start(value, s);
	while (s[++i])
	{
		if (s[i] == '%')
		{
			check_type(s[i + 1], value);
			i++;
		}
		else
			ft_putchar_fd(s[i], 1);
	}
	return (0);
}

int main(void)
{
	int	i;

	i = 48;
	ft_printf("Ola o meu nome e %c %s %p %d %i %u %x %X %% ", 'H', "Ola o meu nome e leo", &i);
}
