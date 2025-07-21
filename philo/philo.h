/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:31:00 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/07 13:30:32 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data	t_data;

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
	t_mutex		meals;
	int			ph_id;
	int			index;
	long		last_meal;
	int			num_meals;
	t_data		*data;
}	t_philo;

typedef struct s_data
{
	t_philo		*philos;
	pthread_t	waiter;
	t_mutex		printlock;
	t_mutex		*fork_mutexes;
	t_mutex		death_mutex;
	long		start_time;
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_eat;
	int			think;
	int			death;
}	t_data;

int		philo_died(t_data *data);
void	update_last_meal(t_philo *philo);
int		lock_printf(t_philo *philo, char *format);
int		time_to_think(t_data *data);
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
int		release_fork(pthread_mutex_t *fork_mutex);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		thinking(t_philo *philo);
long	parse_args(char *s);
int		cleanup(t_data *data, int code);
int		destory_mutexes(t_data *data);
int		has_eaten(t_data *data);
int		detach_threads(t_data *data, int count);

#endif
