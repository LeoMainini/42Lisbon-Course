/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:47:53 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/23 17:51:28 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_str(char const c, char const *set)
{
	while (*set && *set != c)
		set++;
	return (*set != '\0');
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	i = 0;
	while (char_in_str(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (char_in_str(s1[j], set) && j >= 0)
		j--;
	return (ft_substr(s1, i, j + 1 - i));
}
