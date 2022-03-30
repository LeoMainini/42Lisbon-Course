/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:45:29 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/30 14:18:08 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*area;
	size_t	i;

	area = (char *)malloc((count * size) * sizeof(*area));
	if (area == NULL)
		return (NULL);
	i = -1;
	while (++i < count * size)
		area[i] = 0;
	return (area);
}

char	*ft_strjoin(char **s1, char **s2)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	if (!*s2)
		return (NULL);
	i = 0;
	if (*s1)
		while ((*s1)[i] != '\0')
			i++;
	j = 0;
	while ((*s2)[j] != '\0')
		j++;
	result = (char *)malloc((i + j + 1) * sizeof(*result));
	if (result == NULL)
		return (NULL);
	result[i + j] = '\0';
	k = -1;
	while (i > 0 && (*s1)[++k] != '\0')
		result[k] = (*s1)[k];
	k = -1;
	while ((*s2)[++k] != '\0')
		result[i + k] = (*s2)[k];
	free(*s1);
	return (result);
}

char	*ft_strdup(char *s)
{
	int		size;
	char	*r;

	size = 0;
	while (s[size] != '\0')
		size++;
	r = (char *)malloc(size + 1 * (sizeof(*r)));
	if (r == NULL)
		return (NULL);
	r[size] = '\0';
	size = -1;
	while (s[++size] != '\0')
		r[size] = s[size];
	return (r);
}

char	*ft_strchr(const char *s, int c, int len)
{
	int		i;
	char	**sp;

	sp = (char **)&s;
	i = -1;
	while ((*sp)[++i] != '\0')
		if ((*sp)[i] == (unsigned char)c)
			return (&(*sp)[i]);
	if (s[i] == (unsigned char)c && i < len - 1)
		return (&(*sp)[i]);
	return (NULL);
}

