/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:55:04 by leferrei          #+#    #+#             */
/*   Updated: 2022/08/05 17:55:05 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_philo **philos)
{
	int i;
	i = -1;
	philos[0]->data->mutex = (pthread_mutex_t *)malloc(philos[0]->data->n_philos
			* sizeof(pthread_mutex_t));
	philos[0]->data->mutex_index = (int *)malloc(philos[0]->data->n_philos
			* sizeof(int));
	philos[0]->data->death_mutex = (pthread_mutex_t *)malloc(sizeof(
			pthread_mutex_t));
	while (++i < philos[0]->data->n_philos)
	{
		pthread_mutex_init(&philos[0]->data->mutex[i], NULL);
		philos[0]->data->mutex_index[i] = 0;
	}
}

void	set_start_time(t_philo **philos)
{
	struct timeval	start_time;
	int 			i;

	gettimeofday(&start_time, NULL);
	i = -1;
	while (++i < philos[0]->data->n_philos)
		philos[i]->data->start_time = start_time;
}

long	get_timed(struct timeval start)
{
	long			time_passed;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time_passed = 0;
	time_passed += ((current_time.tv_sec - start.tv_sec) * 1000) +
				   ((current_time.tv_usec - start.tv_usec) / 1000);
	return (time_passed);
}
//0 - thinking
//1 - eating
//2 - sleeping
//3 - die

int get_usec_delta(struct timeval start_time)
{
	struct timeval finish_time;

	gettimeofday(&finish_time, NULL);
	return ((int)(((finish_time.tv_sec - start_time.tv_sec) * 1000000)
				  + finish_time.tv_usec - start_time.tv_usec));
}


void	print_state_change(t_philo *philo, int option) {
	long 		time;
	int 		usec_time;
	static int	complete;

	time = get_timed(philo->data->start_time);
	usec_time = get_usec_delta(philo->data->start_time) / 10000;
	if (option == 0 && !philo->data->complete && !complete)
		printf(" %ld.%dms\t-> philo %d starts thinking\n", time, usec_time, philo->n);
	if (option == 1 && !philo->data->complete && !complete)
		printf(" %ld.%dms\t-> philo %d picks up fork\n", time, usec_time, philo->n);
	if (option == 2 && !philo->data->complete && !complete)
		printf(" %ld.%dms\t-> philo %d starts eating\n", time, usec_time, philo->n);
	if (option == 3 && !philo->data->complete && !complete)
		printf(" %ld.%dms\t-> philo %d starts sleeping\n", time, usec_time, philo->n);
	if (option == 4 && !philo->data->complete && !complete)
	{
		printf(" %ld.%dms\t-> philo %d died\n", time, usec_time, philo->n);
		complete = -1;
	}
}
