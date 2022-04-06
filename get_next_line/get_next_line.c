/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:49 by leferrei          #+#    #+#             */
/*   Updated: 2022/04/06 16:26:19 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*


void ft_putstr(char *str);

static void	clean_temp(char *temp)
{
	int	i;

	i = -1;
	while (++i < 31)
		temp[i] = '\0';
}

int	output_index_generator(long long n_l, int neg, char *temp)
{
	int	i;

	clean_temp(temp);
	temp[31] = '\0';
	i = 30;
	while (n_l != 0 && i >= 0)
	{
		temp[i] = "0123456789"[n_l % 10];
		i--;
		n_l = n_l / 10;
	}
	if (neg == 1)
		temp[i] = '-';
	else
		i++;
	return (i);
}



void	ft_putnbr(long n)
{
	long long	n_l;
	int		i;
	char	temp[32];
	int		neg;

	n_l = (long long)n;
	neg = 0;
	if (n_l < 0)
	{
		neg = 1;
		n_l = -n_l;
	}
	if (n_l == 0)
		ft_putstr("0");
	else
	{
		i = 0;
		i = output_index_generator(n_l, neg, temp);
		ft_putstr(&temp[i]);
	}
}



*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest == NULL && src == NULL)
		return (0);
	if (dest > src)
	{
		i = (int)n;
		while (--i >= 0)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		i = -1;
		while (++i < (int)n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	**str;

	str = (char **)&s;
	index = 0;
	while (index < n)
	{
		(*str)[index] = '\0';
		index++;
	}
}

char *get_next_line(int fd)
{
	int	response;
	static char buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char *read_data;
	long i;
	long j;
	char temp[BUFFER_SIZE + 1];

	read_data = NULL;
	while (fd >= 0 && fd < FOPEN_MAX && BUFFER_SIZE > 0)
	{
		i = 0;
		j = 0;
		if (!read_data)
			read_data = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
		ft_memmove(temp, buf[fd], BUFFER_SIZE + 1);
		response = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][BUFFER_SIZE] = '\0';
		if ((i = (long)ft_strchr(temp, '\n', BUFFER_SIZE - 1))
		   && response > 0)
		{
			//ft_putstr("found \\n in buf-> ");
			read_data = ft_sj(&read_data, (char *)(i + 1));
			//memmove(buf[fd], (char *)(i + 1), );
		}
		if (response  > 0)
			read_data = ft_sj(&read_data, (char *)buf[fd]);
		if (!read_data)
			return (0);
		if ((i = (long)ft_strchr(read_data, '\n', ft_strlen(read_data))))
		{
		/*	ft_putstr("found \\n in read data-> ");
			//i = i - (long)read_data + 1;
			ft_putstr(" len = ");
			ft_putnbr(i - (long)read_data + 1);
			ft_putstr(" ");*/
			//if ((i = (long)ft_strchr(buf[fd], '\n', ft_strlen(buf[fd]))))
			//	ft_memmove(buf[fd], (char *)(i + 1), (i + 1) - (long)buf[fd]);
			return (ft_substr(&read_data, 0, i - (long)read_data + 1));
		}
		else if ((i = (long)ft_strchr(buf[fd], '\n', ft_strlen(buf[fd])))
				&& response <= 0)
		{
		//	ft_putstr("found \\n in buf after start -->");
			j = (i - (long)buf[fd] + 1);
			
		/*	ft_putstr("\n\n CURRENT BUFFER \n\n");
			ft_putstr(buf[fd]);
			ft_putstr("\n");
			ft_putstr("MEMMOVE LENGHT =");
			ft_putnbr(ft_strlen(buf[fd]) - j);
			ft_putstr("\n");
		*/	
			ft_memmove(buf[fd], (char *)(i + 1), ft_strlen(buf[fd]) - j);
			ft_bzero(&buf[fd][ft_strlen(buf[fd]) - j], j);
			read_data = ft_sj(&read_data, buf[fd]);
			i = (long)ft_strchr(read_data, '\n', ft_strlen(read_data));
			if (*read_data && buf[fd][BUFFER_SIZE - 1])
				return (ft_substr(&read_data, 0, i - (long)read_data + 1));
			else
				free(read_data);
			return (0);
		}
		else if (response > 0 && response < BUFFER_SIZE)
		{
		/*	ft_putstr("end of read before buffer -> ");
			ft_putstr("response = ");
			ft_putnbr(response);
			ft_putstr(" ");*/
			if (!(ft_strchr(buf[fd], '\0', BUFFER_SIZE)))
				read_data = ft_substr(&read_data, 0,
						ft_strlen(read_data) - (BUFFER_SIZE - response));
			return (read_data);
		}
		else if(response <= 0)
		{
		//	ft_putstr("found null -> ");
			if (*read_data)
				return(read_data);
			else
				free(read_data);
			return (0);	
		}
		//read_data = ft_sj(&read_data, (char *)buf[fd]);
	}
	return (0);
}

