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

void print_data(t_data *data)
{
	printf("Philos\t= %d\nttd\t= %d ms\ntte\t= %d ms"
		   "\ntts\t= %d ms\neatn\t= %d\n", data->n_philos, data->ttd, data->tte,
		   data->tts, data->eatn);
}

t_philo **init_philo_list(t_data *data)
{
	t_philo	**philos;
	int i;

	philos = (t_philo **)malloc(data->n_philos * sizeof(t_philo *));
	i = -1;
	while (++i < data->n_philos)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		philos[i]->n = i + 1;
		philos[i]->state = -1;
		philos[i]->eat_n = 0;
		philos[i]->forks_in_hand = 0;
		philos[i]->data = data;
	}
	return (philos);
}

t_philo	**init_state(int argc, char **argv, t_data *data)
{
	if (check_args(argc, argv))
	{
		data->n_philos = ft_atoi(argv[1]);
		data->ttd = ft_atoi(argv[2]);
		data->tte = ft_atoi(argv[3]);
		data->tts = ft_atoi(argv[4]);
		data->complete = 0;
		if (argc > 5)
			data->eatn = ft_atoi(argv[5]);
		else
			data->eatn = -1;
		gettimeofday(&data->start_time, NULL);
		printf("current time = %ld\n", data->start_time.tv_usec);
		print_data(data);
		return (init_philo_list(data));
	}
	return (0);
}