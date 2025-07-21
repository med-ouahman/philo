/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:41:15 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/19 13:46:23 by mouahman         ###   ########.fr       */
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
# include <signal.h>
# include <fcntl.h>

# define FORKS "/forks"
# define DEATH "/death"
# define TRY_EAT "/try_eat"
# define PRINT "/print"

typedef struct s_philo  t_philo;
typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mtx;

typedef enum e_bool
{
	false,
	true
}   t_bool;

typedef struct s_data
{
	t_th		wait;
	sem_t		*death_sem;
	sem_t		*printlock;
	sem_t		*forks;
	int			num_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			time_to_think;
	int			num_eat;
	int			died;
	long		start_time;
	pthread_t	waiter;
	t_philo		*philos;
	sem_t		*meal_sem;
}   t_data;

typedef struct s_philo
{
	pid_t	pid;
	long	last_meal;
	int		id;
	int		num_meals;
	int		index;
	int		is_eating;
	t_data	*data;

}   t_philo;

int		cleanup(t_data *, int);
void	print_data(t_data *);
int		rip(t_philo *philo);
int		lock_printf(t_philo *philo, char *format);
int		philo_died(t_philo *);
int 	usage(void);
int		init(t_data *data, int ac, char **av);
long	parse_args(char *s);
long	current_time(void);
long	time_diff(long start_time);
int		simulation(t_data *data);
t_philo	*create_philos(int num_philos);
int		wait_children(t_data *);
int		init_philos(t_data *data);
int		request_fork(t_philo *);
int 	release_forks(t_philo *philo);
int		eating(t_philo *);
int		sleeping(t_philo *);
int		thinking(t_philo *);
void	update_last_meal(t_philo *);
int		get_time_to_think(t_data *data);

#endif
