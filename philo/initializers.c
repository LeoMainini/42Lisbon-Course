/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:32:28 by leferrei          #+#    #+#             */
/*   Updated: 2022/12/19 17:55:26 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philo_list(t_data *data)
{
	t_philo	**philos;
	int		i;

	philos = (t_philo **)malloc(data->n_p * sizeof(t_philo *));
	if (!philos)
		return (0);
	i = -1;
	while (++i < data->n_p)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			return (0);
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
		{
			if (ft_atoi(argv[5]) > 0)
				data->en = ft_atoi(argv[5]);
			else if (printf("Error\n"))
				return (0);
		}
		else
			data->en = -1;
		gettimeofday(&data->start_time, NULL);
		data->not_eating = 0;
		data->dead_threads = 0;
		return (init_philo_list(data));
	}
	return (0);
}

int	check_allocated_memory(t_data *data, pthread_t **philo_threads, int **rets)
{
	if (!data->clear_mutex || !data->death_mutex || !data->print_mutex
		|| !data->mutex_index || !data->mutex || !*philo_threads
		|| !*rets)
	{
		free(*philo_threads);
		free(*rets);
		free(data->mutex);
		free(data->mutex_index);
		free(data->death_mutex);
		free(data->print_mutex);
		free(data->clear_mutex);
		printf("Error\n");
		return (0);
	}
	pthread_mutex_init(data->death_mutex, NULL);
	pthread_mutex_init(data->print_mutex, NULL);
	pthread_mutex_init(data->clear_mutex, NULL);
	return (1);
}

int	init_sim_state(t_philo **philos, pthread_t **philo_threads, int **rets)
{
	int	i;

	*philo_threads = (pthread_t *)malloc(philos[0]->dt->n_p
			* sizeof(pthread_t));
	*rets = (int *)malloc(philos[0]->dt->n_p * sizeof(int *));
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
	if (!check_allocated_memory(philos[0]->dt, philo_threads, rets))
		return (-1);
	i = -1;
	while (++i < philos[0]->dt->n_p)
	{
		pthread_mutex_init(&philos[0]->dt->mutex[i], NULL);
		philos[0]->dt->mutex_index[i] = 0;
	}
	return (0);
}
