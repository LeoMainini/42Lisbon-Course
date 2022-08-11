/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:54:55 by leferrei          #+#    #+#             */
/*   Updated: 2022/08/05 17:54:59 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

void set_indexes(t_philo *philo, int *prev, int *next)
{
	if (philo->n == philo->data->n_philos)
	{
		*next = 0;
		*prev = philo->n - 2;
	}
	else if (philo->n == 1)
	{
		*prev = philo->data->n_philos - 1;
		*next = philo->n;
	}
	else
	{
		*prev = philo->n - 2;
		*next = philo->n;
	}
}

void	lock_forks_set_state(t_philo *philo)
{
	int prev_n;
	int next_n;

	set_indexes(philo,&prev_n,&next_n);
	if (philo->forks_in_hand == 0)
	{
		pthread_mutex_lock(&philo->data->mutex[next_n]);
		pthread_mutex_lock(&philo->data->mutex[prev_n]);
		print_state_change(philo, 1);
		philo->forks_in_hand++;

	}
	else
	{
		print_state_change(philo, 1);
		print_state_change(philo, 2);
		gettimeofday(&philo->eat_time, NULL);
		usleep(philo->data->tte * 1000);
		philo->eat_n += 1;
		philo->forks_in_hand = 0;
		philo->state += 1;
		pthread_mutex_unlock(&philo->data->mutex[prev_n]);
		pthread_mutex_unlock(&philo->data->mutex[next_n]);
	}
}

void	unlock_forks(t_philo *philo)
{
	int prev_n;
	int next_n;

	set_indexes(philo,&prev_n,&next_n);
	pthread_mutex_unlock(&philo->data->mutex[prev_n]);
	pthread_mutex_unlock(&philo->data->mutex[next_n]);
	pthread_mutex_unlock(&philo->data->mutex[philo->n - 1]);
}

void decide_state_change(t_philo *philo)
{
		if (philo->state == -1 || philo->state == 2)
		{
			print_state_change(philo, 0);
			philo->state = 0;
		}
		else if (philo->state == 0)
		{
			pthread_mutex_lock(&philo->data->mutex[philo->n - 1]);
			lock_forks_set_state(philo);
			pthread_mutex_unlock(&philo->data->mutex[philo->n - 1]);
		}
		else if (philo->state == 1)
		{
			print_state_change(philo, 3);
			usleep(philo->data->tts * 1000);
			philo->state += 1;
		}
}

void *sim_routine(void *ph)
{
	t_philo			*philo;

	if (!ph)
		return (0);
	philo = (t_philo *)ph;
	if (philo->n % 2 == 0)
		usleep(500);
	philo->eat_time = philo->data->start_time;
	while (!philo->data->complete)
	{
		if (get_timed(philo->eat_time) > philo->data->ttd)
		{
			philo->data->complete = 1;
			unlock_forks(philo);
			print_state_change(philo, 4);
			return ((void *)&philo->state);
		}
		decide_state_change(philo);
	}
	return ((void *)&philo->state);
}

void initiate_simulation(t_philo **philos)
{
	pthread_t		philo_threads[philos[0]->data->n_philos];
	pthread_mutex_t	*mutex;
	int 			*returns[philos[0]->data->n_philos];
	int 			*input_i;
	int 			i;

	set_start_time(philos);
	mutex = (pthread_mutex_t *)malloc(philos[0]->data->n_philos
			* sizeof(pthread_mutex_t));
	init_mutex(philos, mutex);
	i = -1;
	while (++i < philos[0]->data->n_philos)
	{
		input_i = &i;
		pthread_create(philo_threads + i, NULL, &sim_routine, philos[*input_i]);
	}
	i = -1;
	while (++i < philos[0]->data->n_philos)
		pthread_join(philo_threads[i], (void **)&returns[i]);
	free(mutex);
	//pthread_mutex_destroy(philos[0]->mutex);
}