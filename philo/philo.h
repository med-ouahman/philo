/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:31:00 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/29 21:56:26 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data		t_data;

typedef pthread_mutex_t	t_mutex;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_philo
{
	pthread_t	th_id;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		meal_lock;
	int			ph_id;
	int			index;
	int			ph_fork;
	int			has_eaten;
	int			is_eating;
	int			is_thinking;
	int			is_sleeping;
	long		last_meal;
	int			last_action;
	int			num_meals;
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_t		waiter;
	pthread_mutex_t	printlock;
	pthread_mutex_t	*fork_mutexes;
	pthread_mutex_t	death_mutex;
	long			start_time;
	int				num_philos;
	int				time_to_die;
	int				death;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat;
}	t_data;

int		usage(void);
int		init(t_data *data, int ac, char **av);
int		ft_atoi(const char *nptr);
void	*simulation(void *arg);
void	*wait_for_death(void *arg);
int		create_threads(t_data *data);
int		init_philos(t_data *data);
long	current_time(void);
t_philo	*create_philos(int num_philos);
long	time_diff(long start_time);
t_mutex	*init_fork_mutex(int num_philos);
int		request_fork(t_philo *philo, pthread_mutex_t *fork_mutex);
int		join_threads(t_philo *philos);
int		relase_fork(pthread_mutex_t *fork_mutex);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);
long	parse_args(char *s);
int		cleanup(t_data *data, int code);
int		destory_mutex(t_data *data);

#endif
