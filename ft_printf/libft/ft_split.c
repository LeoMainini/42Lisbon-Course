/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:44:32 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/10 18:02:01 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static void	separate_words(char **result, const char *s, char c, int i)
{
	int	j;
	int	k;
	int	l;

	l = 0;
	i = -1;
	j = 0;
	k = 0;
	while (s[++i] != '\0' && !(s[0] == '\0'))
	{
		if (((s[i] == c) && s[i + 1] != c) || s[i + 1] == '\0')
		{
			result[j] = (char *)malloc((i - k + 1) * sizeof(char));
			printf("%d\n", i);
			l = 0;
			while (s[k] != c && s[k] != '\0')
			{
				result[j][l] = s[k];
				l++;
				k++;
			}
			result[j][l] = '\0';
			printf("%s\n", result[j]);
			k = i + 1;
			j++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words;
	char	**result;

	i = 0;
	words = 0;
	if (!s)
		return (NULL);
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

int main(void)
{
	ft_split("           a              ", ' ');
}
