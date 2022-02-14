/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:44:32 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/14 18:01:25 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	separate_words(char **result, const char *s, char c, int i)
{
	int	j;
	int	k;
	int	l;

	l = 0;
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i + 1] == '\0')
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
	while (s[i] != '\0')
	{
		if (s[i] == c)
			words++;
		i++;
	}
	if (words == 0)
		return (NULL);
	result = (char **)malloc((words + 2) * sizeof(char *));
	if (result == 0)
		return (NULL);
	result[words] = (char *) NULL;
	separate_words(result, s, c, 0);
	return (result);
}

int main(void)
{
	char *test = "ola o meu nome e leo";
	char **test_o = ft_split(test, ' ');
	for (int i = 0; i < 7; i++)
		printf("%p\n", test_o[i]);

}
