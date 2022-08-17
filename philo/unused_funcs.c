/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:41:33 by leferrei          #+#    #+#             */
/*   Updated: 2022/08/17 18:41:36 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_usec_delta(struct timeval start_time)
{
	struct timeval	finish_time;

	gettimeofday(&finish_time, NULL);
	return ((int)(((finish_time.tv_sec - start_time.tv_sec) * 1000000)
		+ finish_time.tv_usec - start_time.tv_usec));
}

void	print_data(t_data *data)
{
	printf("Philos\t= %p\nttd\t= %p ms\ntte\t= %p ms"
		"\ntts\t= %p ms\neatn\t= %p\ncomplete\t= %p\nnot_eating\t= %p\n",
		&data->n_p, &data->ttd, &data->tte,
		&data->tts, &data->en, &data->complete, &data->not_eating);
}
