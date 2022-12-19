/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leferrei <leferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:33:27 by leferrei          #+#    #+#             */
/*   Updated: 2022/12/19 17:36:14 by leferrei         ###   ########.fr       */
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
	int				n_p;
	int				ttd;
	int				tte;
	int				tts;
	int				complete;
	int				en;
	int				not_eating;
	int				dead_threads;
	struct timeval	start_time;
	int				*mutex_index;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*clear_mutex;
}	t_data;

typedef struct s_philo {
	int				n;
	int				en;
	t_data			*dt;
	struct timeval	eat_time;
}	t_philo;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
int		check_args(int argc, char **argv);
t_philo	**init_philo_list(t_data *data);
t_philo	**init_state(int argc, char **argv, t_data *data);
void	initiate_simulation(t_philo **philos);
void	set_start_time(t_philo **philos);
long	get_timed(struct timeval start);
int		init_sim_state(t_philo **philos, pthread_t **philo_threads, int **rets);
void	print_state_change(t_philo *philo, int option);
void	set_indexes(t_philo *philo, int *prev, int *next);
void	unlock_all_forks(t_philo *philo);
void	cleanup_exit(t_philo **philos, pthread_t *philo_threads, int *returns);
int		is_dead(t_philo *philo);
int		unlock_forks_return_status(t_philo *philo, int prev,
			int next, int status);
void	eat_sleep_increment(t_philo *philo);
void	death_checker(t_philo **philos);

#endif
