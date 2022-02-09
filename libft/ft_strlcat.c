/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:44:39 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/08 21:36:01 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1 && size > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size > 0 && i < size)
		dst[i] = '\0';
	if (i > size)
		return (i - 1 + size);
	return (i);
}

int main(void)
{
	int	i;
	int	i2;
	int	i3;
	int	i4;
	int	i5;
	int	i6;
	char *test = "123";
	char leo1[8] = "leo1";
	char lib1[8] = "lib1";
	char leo2[8] = "leo2";
	char lib2[8] = "lib2";
	char leo3[8] = "leo3";
	char lib3[8] = "lib3";
	i = ft_strlcat(leo1, test, 0);
	i2 = ft_strlcat(leo2, test, 3);
	i3 = ft_strlcat(leo3, test, 10);
//	i4 = strlcat(lib1, test, 0);
//	i5 = strlcat(lib2, test, 3);
//	i6 = strlcat(lib3, test, 10);
	printf("i = %s, i2 = %s, i3 = %s\ni4 = %d, i5 = %d, i6 = %d\n",leo1 , leo2, leo3, i4, i5, i6);

}
