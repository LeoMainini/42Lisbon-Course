/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:43:11 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/30 18:00:30 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int main(void)
{
	int fd = open("test_no_nl.txt", O_RDONLY);
	//fd = 5000;
	//printf("fd = %d\n", fd);
	printf("No \\n\n\n");
	char *c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	printf("\n\n");
	fd =  open("test.txt", O_RDONLY);
	printf("With \\n\n\n");
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	printf("\n\n");
	printf("From stdin\n\n");
	ft_putstr("Type something: ");
	c = get_next_line(0);
	printf("%s", c);
	free(c);
	printf("\n\n");
	printf("with \\0\n\n");
	fd =  open("test_slash_0.txt", O_RDONLY);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);
	c = get_next_line(fd);
	printf("%s", c);
	free(c);

}
