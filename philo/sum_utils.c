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

void	init_mutex(t_philo **philos, pthread_mutex_t *mutex)
{
	int i;
	i = -1;
	while (++i < philos[0]->data->n_philos)
		pthread_mutex_init(&mutex[i], NULL);
	i = -1;
	while (++i < philos[0]->data->n_philos)
		philos[i]->data->mutex = mutex;

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
//1 - pick fork
//2 - eating
//3 - sleeping
//4 - die

void	print_state_change(t_philo *philo, int option)
{
	long	time;

	time = get_timed(philo->data->start_time);
	if (option == 0)
		printf("  %ldms\t-> philo %d starts thinking\n", time, philo->n);
	if (option == 1)
		printf("  %ldms\t-> philo %d picks up fork\n", time, philo->n);
	if (option == 2)
		printf("  %ldms\t-> philo %d starts eating\n", time, philo->n);
	if (option == 3)
		printf("  %ldms\t-> philo %d starts sleeping\n", time, philo->n);
	if (option == 4)
		printf("  %ldms\t-> philo %d died\n", time, philo->n);
}

