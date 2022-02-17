/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:44:34 by leferrei          #+#    #+#             */
/*   Updated: 2022/02/17 13:23:15 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		result;
	char	**sp;

	sp = (char **)&s;
	i = -1;
	result = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			result = i;
	if (s[i] == c)
		return (&(*sp)[i]);
	if (result != -1)
		return (&(*sp)[result]);
	return (NULL);
}
