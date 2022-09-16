/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:50:08 by leferrei          #+#    #+#             */
/*   Updated: 2022/08/17 19:50:09 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

void	set_indexes(t_philo *philo, int *prev, int *next)
{
	if (philo->n == philo->dt->n_p)
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

int	is_dead(t_philo *philo)
{
	if (get_timed(philo->eat_time) < philo->dt->ttd)
		return (0);
	pthread_mutex_lock(philo->dt->death_mutex);
	print_state_change(philo, 4);
	philo->dt->complete = 1;
	pthread_mutex_unlock(philo->dt->death_mutex);
	return (1);
}

void	unlock_all_forks(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->dt->n_p)
	{
		if (philo->dt->mutex_index[i] == 1)
		{
			pthread_mutex_unlock(&philo->dt->mutex[i]);
			philo->dt->mutex_index[i] = 0;
		}
	}
}

int	unlock_forks_return_status(t_philo *philo, int prev, int next, int status)
{
	pthread_mutex_unlock(&philo->dt->mutex[prev]);
	pthread_mutex_unlock(&philo->dt->mutex[next]);
	philo->dt->mutex_index[next] = 0;
	philo->dt->mutex_index[prev] = 0;
	return (status);
}

void	eat_sleep_increment(t_philo *philo)
{
	print_state_change(philo, 2);
	gettimeofday(&philo->eat_time, NULL);
	usleep(philo->dt->tte * 1000);
	philo->en += 1;
}
