/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:47:53 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/21 13:12:00 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_byte_size(char const *s1, char const *set)
{
	int	size;
	int	i;
	int	j;

	i = -1;
	size = 0;
	while (s1[++i] != '\0')
	{
		j = -1;
		while (set[++j] != '\0')
		{
			if (set[j] == s1[j])
				break ;
		}
		if (set[j] == '\0')
			size++;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = get_byte_size(s1, set);
	str = (char *)malloc(i + 1 * (sizeof(*str)));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i = -1;
	k = 0;
	while (s1[++i] != '\0')
	{
		j = -1;
		while (set[++j] != '\0')
			if (set[j] == s1[j])
				break ;
		if (set[j] == '\0')
		{
			str[k] = s1[i];
			k++;
		}
	}
	return (str);
}
