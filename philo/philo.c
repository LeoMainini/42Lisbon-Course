/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:25:39 by leferrei          #+#    #+#             */
/*   Updated: 2022/08/03 17:25:41 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//#TODO: Input mutex addrs in philo struct
//#TODO: Create check print and change philo state function to lock arround
//#TODO: Calculate and print time of philo actions


int	main(int argc, char **argv)
{
	t_data	data;
	t_philo **philos;
	int 	i;

	if ((argc < 5 && printf("Missing arguments.\n"))
		|| (argc > 6 && printf("Too many arguments.\n"))) {
		return (1);
	}
	philos = init_state(argc,argv,  &data);
	if (!philos)
		return (0);
	initiate_simulation(philos);
	i = -1;
	while (++i < data.n_philos)
		free(philos[i]);
	free(philos);
}
