/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:33:27 by leferrei          #+#    #+#             */
/*   Updated: 2022/08/03 17:35:12 by leferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_data {
	int		n_philos;
	int		ttd;
	int		tte;
	int		tts;
	int		eatn;
	int 	i;
}	t_data;

//state 0 = thinking;
//state 1 = pick fork
//state 2 = eating
//state 3 = sleeping
//state 4 = died
typedef struct s_philo {
	int n;
	int state;
	int forks_av;
	t_data *data;
}	t_philo;

char    **ft_split(char const *s, char c);
int     ft_atoi(const char *nptr);
int	check_args(int argc, char **argv);
t_philo **init_philo_list(t_data *data);
t_philo	**init_state(int argc, char **argv, t_data *data);
void initiate_simulation(t_philo **philos);

#endif
