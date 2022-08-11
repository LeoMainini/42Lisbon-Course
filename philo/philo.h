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
# include <sys/time.h>

typedef struct s_data {
	int		n_philos;
	int		ttd;
	int		tte;
	int		tts;
	int 	complete;
	int		eatn;
	struct timeval start_time;
	pthread_mutex_t	*mutex;
}	t_data;

//state 0 = thinking;
//state 1 = eating
//state 2 = sleeping
//state 3 = died
typedef struct s_philo {
	int				n;
	int 			eat_n;
	int				state;
	int				forks_in_hand;
	t_data			*data;
	struct timeval	eat_time;
}	t_philo;

char    **ft_split(char const *s, char c);
int     ft_atoi(const char *nptr);
int	check_args(int argc, char **argv);
t_philo **init_philo_list(t_data *data);
t_philo	**init_state(int argc, char **argv, t_data *data);
void initiate_simulation(t_philo **philos);
void	set_start_time(t_philo **philos);
long get_timed(struct timeval start);
void	init_mutex(t_philo **philos, pthread_mutex_t *mutex);
void	print_state_change(t_philo *philo, int option);

#endif
