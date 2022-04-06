/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:43:11 by leferrei          #+#    #+#             */
/*   Updated: 2022/04/05 23:37:59 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void ft_putstr(char *str)
{
	if (!str)
		write(1, "(null)", 6);
	else
		while (*str != '\0')
			write(1, str++, 1);
}

int main(void)
{
	int fd = open("test_no_nl.txt", O_RDONLY);
	//fd = 5000;
	//ft_putstr("fd = %d\n", fd);
	ft_putstr("No \\n\n\n");
	char *c = get_next_line(fd);
	ft_putstr(c);
	free(c);
	c = get_next_line(fd);
	ft_putstr(c);
	free(c);
	ft_putstr("\n\n");
	fd =  open("test.txt", O_RDONLY);
	ft_putstr("With \\n\n\n");
	c = get_next_line(fd);//
	ft_putstr(c);
	free(c);
	c = get_next_line(fd);//
	ft_putstr(c);
	free(c);
	c = get_next_line(fd);//
	ft_putstr(c);
	free(c);
	c = get_next_line(fd);//
	ft_putstr(c);
	free(c);
	c = get_next_line(fd);//
	ft_putstr(c);
	free(c);
	c = get_next_line(fd);//
	ft_putstr(c);
	free(c);
	c = get_next_line(fd);
	ft_putstr(c);
	free(c);
	ft_putstr("\n\n");
	ft_putstr("From stdin\n\n");
	ft_putstr("Type something: ");
	c = get_next_line(0);//
	ft_putstr(c);
	free(c);
	ft_putstr("\n\n");
	ft_putstr("with \\0\n\n");
	fd =  open("test_slash_0.txt", O_RDONLY);
	c = get_next_line(fd);
	ft_putstr(c);
	free(c);
	ft_putstr("  |  ");
	c = get_next_line(fd);
	ft_putstr(c);
	free(c);

}
