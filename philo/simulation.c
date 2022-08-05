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

void *sim_routine(void *ph)
{
	t_philo *philo;
	if (!ph)
		return (0);
	philo = (t_philo *)ph;
	//pthread_mutex_lock();
	printf("thread for philo %d out of %d initialized\n", philo->n, philo->data->n_philos);
	//pthread_mutex_unlock();
	//free(ph);
	return ((void *)&philo->n);
}

void initiate_simulation(t_philo **philos)
{
	pthread_mutex_t	mutex;
	pthread_t		philo_threads[philos[0]->data->n_philos];
	int 			*returns[philos[0]->data->n_philos];
	int 			*input_i;
	int 			i;

	pthread_mutex_init(&mutex, NULL);
	i = -1;
	while (++i < philos[0]->data->n_philos)
	{
		input_i = &i;
		printf("current before thread = %d\n", philos[*input_i]->n);
		pthread_create(philo_threads + i, NULL, &sim_routine, philos[*input_i]);
	}
	i = -1;
	while (++i < philos[0]->data->n_philos)
	{
		pthread_join(philo_threads[i], (void **)&returns[i]);
		printf("thread %d finished exec, return = %d\n", i, *returns[i]);
	}
	pthread_mutex_destroy(&mutex);
}