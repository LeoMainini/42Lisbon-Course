/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:32:28 by leferrei          #+#    #+#             */
/*   Updated: 2022/08/04 15:32:29 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philo_list(t_data *data)
{
	t_philo	**philos;
	int		i;

	philos = (t_philo **)malloc(data->n_p * sizeof(t_philo *));
	i = -1;
	while (++i < data->n_p)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		philos[i]->n = i + 1;
		philos[i]->en = 0;
		philos[i]->dt = data;
	}
	return (philos);
}

t_philo	**init_state(int argc, char **argv, t_data *data)
{
	if (check_args(argc, argv))
	{
		data->n_p = ft_atoi(argv[1]);
		data->ttd = ft_atoi(argv[2]);
		data->tte = ft_atoi(argv[3]);
		data->tts = ft_atoi(argv[4]);
		data->complete = 0;
		if (argc > 5)
			data->en = ft_atoi(argv[5]);
		else
			data->en = -1;
		gettimeofday(&data->start_time, NULL);
		data->not_eating = 0;
		data->dead_threads = 0;
		return (init_philo_list(data));
	}
	return (0);
}

void	init_sim_state(t_philo **philos, pthread_t **philo_threads, int **rets)
{
	int	i;

	*philo_threads = (pthread_t *)malloc(philos[0]->dt->n_p
			* sizeof(pthread_t));
	*rets = (int *)malloc(philos[0]->dt->n_p * sizeof(int));
	philos[0]->dt->mutex = (pthread_mutex_t *)malloc(philos[0]->dt->n_p
			* sizeof(pthread_mutex_t));
	philos[0]->dt->mutex_index = (int *)malloc((philos[0]->dt->n_p + 1)
			* sizeof(int));
	philos[0]->dt->death_mutex = (pthread_mutex_t *)malloc(sizeof(
				pthread_mutex_t));
	philos[0]->dt->print_mutex = (pthread_mutex_t *)malloc(sizeof(
				pthread_mutex_t));
	philos[0]->dt->clear_mutex = (pthread_mutex_t *)malloc(sizeof(
				pthread_mutex_t));
	pthread_mutex_init(philos[0]->dt->death_mutex, NULL);
	pthread_mutex_init(philos[0]->dt->print_mutex, NULL);
	pthread_mutex_init(philos[0]->dt->clear_mutex, NULL);
	i = -1;
	while (++i < philos[0]->dt->n_p)
	{
		pthread_mutex_init(&philos[0]->dt->mutex[i], NULL);
		philos[0]->dt->mutex_index[i] = 0;
	}
}
