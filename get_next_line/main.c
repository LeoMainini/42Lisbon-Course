/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:43:11 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/18 17:28:25 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	char *c = get_next_line(fd);
	printf("%s\n", c);
	c = get_next_line(fd);
	printf("%s\n", c);
	c = get_next_line(fd);
	printf("%s\n", c);
	c = get_next_line(fd);
	printf("%s\n", c);
	c = get_next_line(fd);
	printf("%s\n", c);
	c = get_next_line(fd);
	printf("%s\n", c);






}
