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

void	set_start_time(t_philo **philos)
{
	struct timeval	start_time;
	int				i;

	gettimeofday(&start_time, NULL);
	i = -1;
	while (++i < philos[0]->dt->n_p)
		philos[i]->dt->start_time = start_time;
}

long	get_timed(struct timeval start)
{
	long			time_passed;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	time_passed = 0;
	time_passed += ((current_time.tv_sec - start.tv_sec) * 1000)
		+ ((current_time.tv_usec - start.tv_usec) / 1000);
	return (time_passed);
}

void	print_state_change(t_philo *philo, int option)
{
	long		time;
	static int	complete;

	pthread_mutex_lock(philo->dt->print_mutex);
	time = get_timed(philo->dt->start_time);
	if (option == 0 && !philo->dt->complete && !complete)
		printf(" %ldms\t~> %d is thinking\n", time, philo->n);
	if (option == 1 && !philo->dt->complete && !complete)
		printf(" %ldms\t~> %d has taken a fork\n", time, philo->n);
	if (option == 2 && !philo->dt->complete && !complete)
		printf(" %ldms\t~> %d is eating\n", time, philo->n);
	if (option == 3 && !philo->dt->complete && !complete)
		printf(" %ldms\t~> %d is sleeping\n", time, philo->n);
	if (option == 4 && !philo->dt->complete && !complete)
	{
		printf(" %ldms\t~> %d died\n", time, philo->n);
		complete = 1;
	}
	pthread_mutex_unlock(philo->dt->print_mutex);
}

void	cleanup_exit(t_philo **philos, pthread_t *philo_threads, int *returns)
{
	int	i;

	i = -1;
	if (philos[0]->dt->dead_threads == philos[0]->dt->n_p)
		while (++i < philos[0]->dt->n_p)
		{
			pthread_mutex_destroy(philos[0]->dt->mutex[i]);
			free(philos[0]->dt->mutex[i]);
		}
	pthread_mutex_destroy(philos[0]->dt->death_mutex);
	pthread_mutex_destroy(philos[0]->dt->print_mutex);
	pthread_mutex_destroy(philos[0]->dt->clear_mutex);
	free(returns);
	free(philo_threads);
	free(philos[0]->dt->mutex);
	free(philos[0]->dt->mutex_index);
	free(philos[0]->dt->death_mutex);
	free(philos[0]->dt->print_mutex);
	free(philos[0]->dt->clear_mutex);
}
