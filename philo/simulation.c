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
		*prev = philo->n - 1;
	}
	else if (philo->n == 1)
	{
		*prev = 0;
		*next = philo->n;
	}
	else
	{
		*prev = philo->n - 1;
		*next = philo->n;
	}
}

int is_dead(t_philo *philo)
{
	if (get_timed(philo->eat_time) < philo->data->ttd)
		return (0);
	pthread_mutex_lock(philo->data->death_mutex);
	print_state_change(philo, 4);
	philo->data->complete = 1;
	pthread_mutex_unlock(philo->data->death_mutex);
	return (1);
}

int	lock_right(t_philo *philo, int prev_n, int next_n)
{
	pthread_mutex_lock(&philo->data->mutex[next_n]);
	if (is_dead(philo))
		return (0);
	print_state_change(philo, 1);
	philo->data->mutex_index[next_n] = 1;
	print_state_change(philo, 2);
	gettimeofday(&philo->eat_time, NULL);
	usleep(philo->data->tte * 1000);
	philo->eat_n += 1;
	philo->data->mutex_index[prev_n] = 0;
	philo->data->mutex_index[next_n] = 0;
	pthread_mutex_unlock(&philo->data->mutex[prev_n]);
	pthread_mutex_unlock(&philo->data->mutex[next_n]);
	if (is_dead(philo))
		return (0);
	return (1);
}
int lock_left(t_philo *philo, int prev_n, int next_n)
{
	pthread_mutex_lock(&philo->data->mutex[prev_n]);
	philo->data->mutex_index[prev_n] = 1;
	print_state_change(philo, 1);
	if (is_dead(philo))
		return (0);
	if (next_n == prev_n)
		while (1)
			if (is_dead(philo))
				return (0);
	return (1);
}

int	lock_forks_set_state(t_philo *philo)
{
	int prev_n;
	int next_n;

	set_indexes(philo,&prev_n,&next_n);
	if (!philo->data->complete)
	{
		if (!lock_left(philo, prev_n, next_n))
			return (0);
		if (!lock_right(philo, prev_n, next_n))
			return (0);
	}
	return (1);
}

void	unlock_forks(t_philo *philo)
{
	int i;

	i = -1;
	while (++i < philo->data->n_philos)
	{
		if (philo->data->mutex_index[i] == 1)
		{
			pthread_mutex_unlock(&philo->data->mutex[i]);
			philo->data->mutex_index[i] = 0;
		}
	}
}

void decide_state_change(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	print_state_change(philo, 0);
	if (is_dead(philo))
		return ;
	if (!lock_forks_set_state(philo))
		return ;
	print_state_change(philo, 3);
	if (is_dead(philo))
		return ;
	usleep(philo->data->tts * 1000);
	if (is_dead(philo))
		return ;
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
	while (1)
	{
		if (is_dead(philo))
			break ;
		decide_state_change(philo);
	}
	unlock_forks(philo);
	return ((void *)&philo->state);
}

void initiate_simulation(t_philo **philos)
{
	pthread_t		philo_threads[philos[0]->data->n_philos];
	int 			*returns[philos[0]->data->n_philos];
	int 			*input_i;
	int 			i;

	set_start_time(philos);
	init_mutex(philos);
	i = -1;
	while (++i < philos[0]->data->n_philos)
	{
		input_i = &i;
		pthread_create(philo_threads + i, NULL, &sim_routine, philos[*input_i]);
	}
	i = -1;
	while (++i < philos[0]->data->n_philos)
		pthread_join(philo_threads[i], (void **)&returns[i]);
	free(philos[0]->data->mutex);
	free(philos[0]->data->mutex_index);
	free(philos[0]->data->death_mutex);
	free(philos[0]->data->print_mutex);
}