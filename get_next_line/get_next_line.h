/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:41:59 by leferrei          #+#    #+#             */
/*   Updated: 2022/03/29 16:30:18 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char **s1, char **s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char **s, unsigned int start, size_t len);

#endif
