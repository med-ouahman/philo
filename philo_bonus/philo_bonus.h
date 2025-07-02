/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:41:15 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/28 12:12:32 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <pthread.h>
# include <string.h>
# include <fcntl.h>

# define ESTIMATED_TIME_TO_THINK 100

typedef struct s_philo   	t_philo;
typedef pthread_t	t_th;

typedef enum e_bool
{
	false,
	true
}   t_bool;

typedef struct s_data
{
	sem_t		*forks;
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_eat;
	int			died;
	long		start_time;
	pthread_t	waiter;
	t_philo		*philos;
}   t_data;

typedef struct s_philo
{
	t_th	watcher;
	pid_t	pid;
	long	last_meal;
	int		id;
	int		num_meals;
	int		index;
	t_data	*data;

}   t_philo;

void	*waiter(void *p);
int 	usage(void);
int		init(t_data *data, int ac, char **av);
long	parse_args(char *s);
long	current_time(void);
long	time_diff(long start_time);
int		simulation(t_data *data);
t_philo	*create_philos(int num_philos);
int		wait_children(t_data *data);
int		init_philos(t_data *data);
int		request_fork(t_philo *);
int 	release_forks(t_philo *philo);
int		eating(t_philo *);
int		sleeping(t_philo *);
int		thinking(t_philo *);

#endif
