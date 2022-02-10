/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:15:33 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/10 12:05:02 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
		i++;
	return (s1[i] - s2[i]);
}

int main(void)
{
	printf("leo %d\n", ft_strncmp("1", "123456789", 5));
	printf("lib %d\n", strncmp("1", "123456789", 5));
	printf("leo %d\n", ft_strncmp("1", "", 5));
	printf("lib %d\n", strncmp("1", "", 5));
	printf("leo %d\n", ft_strncmp("", "", 5));
	printf("lib %d\n", strncmp("", "", 5));


}
