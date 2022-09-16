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

int	check_forks_lock(t_philo *philo, int prev_n, int next_n)
{
	pthread_mutex_lock(philo->dt->mutex[prev_n]);
	philo->dt->mutex_index[prev_n] = 1;
	print_state_change(philo, 1);
	if (next_n == prev_n)
		while (1)
			if (is_dead(philo))
				return (0);
	pthread_mutex_lock(philo->dt->mutex[next_n]);
	philo->dt->mutex_index[next_n] = 1;
	print_state_change(philo, 1);
	return (1);
}

int	lock_forks_eat(t_philo *philo)
{
	int	prev_n;
	int	next_n;

	set_indexes(philo, &prev_n, &next_n);
	if (!philo->dt->complete)
	{
		if (!check_forks_lock(philo, prev_n, next_n))
			return (unlock_forks_return_status(philo, prev_n, next_n, 0));
		eat_sleep_increment(philo);
		if (philo->en != philo->dt->en)
			return (unlock_forks_return_status(philo, prev_n, next_n, 1));
		philo->dt->not_eating++;
		philo->en++;
	}
	return (unlock_forks_return_status(philo, prev_n, next_n, 1));
}

void	decide_state_change(t_philo *philo)
{
	print_state_change(philo, 0);
	if (is_dead(philo))
		return ;
	if (!lock_forks_eat(philo))
		return ;
	print_state_change(philo, 3);
	if (is_dead(philo))
		return ;
	usleep(philo->dt->tts * 1000);
}

void	*sim_routine(void *ph)
{
	t_philo		*p;
	int			dn;

	p = (t_philo *)ph;
	p->eat_time = p->dt->start_time;
	dn = 0;
	if (p->n % 2 == 0)
		usleep(250);
	while (1)
	{
		if (((p->dt->en == 0) || (p->en > p->dt->en && p->dt->en > -1)) && !dn)
		{
			print_state_change(p, 0);
			dn++;
		}
		if (is_dead(p) || p->dt->n_p == p->dt->not_eating
			|| p->dt->complete)
			break ;
		if ((p->en <= p->dt->en || p->dt->en == -1) && !dn)
			decide_state_change(p);
	}
	unlock_all_forks(p);
	p->dt->dead_threads++;
	pthread_exit((void *)&p->n);
}

void	initiate_simulation(t_philo **philos)
{
	pthread_t	*philo_threads;
	int			*returns;
	int			*input_i;
	int			i;

	set_start_time(philos);
	init_sim_state(philos, &philo_threads, &returns);
	i = -1;
	while (++i < philos[0]->dt->n_p)
	{
		input_i = &i;
		pthread_create(philo_threads + i, NULL, &sim_routine, philos[*input_i]);
	}
	i = -1;
	while (++i < philos[0]->dt->n_p)
		pthread_join(philo_threads[i], (void **)&returns[i]);
	cleanup_exit(philos, philo_threads, returns);
}
