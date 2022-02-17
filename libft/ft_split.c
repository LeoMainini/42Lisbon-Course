/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:44:32 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/17 13:15:48 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	separate_words(char **result, const char *s, char c, int i)
{
	int	j;
	int	k;
	int	l;

	l = 0;
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0' && !(s[0] == '\0'))
	{
		if (((s[i] == c) && s[i + 1] != c) || s[i + 1] == '\0')
		{
			result[j] = (char *)malloc((i - k) * sizeof(char));
			l = 0;
			while (s[k] != c && s[k] != '\0')
			{
				result[j][l] = s[k];
				l++;
				k++;
			}
			k = i + 1;
			j++;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**result;

	i = 0;
	words = 0;
	while (*s == c && c != '\0')
		s++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			words++;
		if (s[i + 1] == '\0' && s[i] != c)
			words++;
		i++;
	}
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (result == 0)
		return (NULL);
	result[words] = (char *) NULL;
	separate_words(result, s, c, 0);
	return (result);
}
