/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:44:32 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/14 16:30:35 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	words;
	char **result;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			words++;
		i++;
	}
	result = (char **)malloc(words * sizeof(char *));
	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i + 1] == '\0')
			{
				result[j] = (char *)malloc((i - k) * sizeof(char));
				printf("s[j] = %d = %s\n",j, &s[k]);
				printf("s[i] = %d = %s\n",i, &s[i]);
				printf("k = %d\n", k);
				l = 0;
				while (s[k] != c && s[k] != '\0')
				{
					result[j][l] = s[k];
					l++;
					k++;
				}
				printf("%s\n", result[j]);
				k = i + 1;
				j++;
			}
		i++;
	}
	return (result);
}

int main(void)
{
	char *test = "ola o meu nome e leo";
	char **test_o = ft_split(test, ' ');
	for (int i = 0; i < 6; i++)
		printf("%s\n", test_o[i]);

}
