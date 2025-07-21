/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:48:10 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/26 14:52:32 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    update_last_meal(t_philo *philo)
{
    philo->last_meal = current_time();
}

int my_usleep(t_philo *philo, long time)
{
    long    now;

    now = current_time() + time;
    while (now > current_time())
    {
        if (philo_died(philo))
        {
            if (philo->is_eating)
                release_forks(philo);
            cleanup(philo->data, 0);
        }
        usleep(10);
    }
    if (philo_died(philo))
        cleanup(philo->data, 0);
    return (0);
}

int eating(t_philo *philo)
{
    if (philo_died(philo))
        cleanup(philo->data, 0);
    request_fork(philo);
    if (philo->data->num_philos == 1)
        my_usleep(philo, philo->data->time_to_die);
    if (philo_died(philo))
    {
        sem_post(philo->data->forks);
        cleanup(philo->data, 0);
    }
    request_fork(philo);
    if (philo_died(philo))
    {
        release_forks(philo);
        cleanup(philo->data, 0);
    }
    update_last_meal(philo);
    lock_printf(philo, "%ld %d is eating\n");
    philo->is_eating = 1;
    my_usleep(philo, philo->data->time_to_eat);
	release_forks(philo);
    philo->is_eating = 0;
    return (0);
}

int sleeping(t_philo *philo)
{
    if (philo_died(philo))
        cleanup(philo->data, 0);
    lock_printf(philo, "%ld %d is sleeping\n");
    my_usleep(philo, philo->data->time_to_sleep);
    return (0);
}

int thinking(t_philo *philo)
{
    if (philo_died(philo))
        exit(1);
    lock_printf(philo, "%ld %d is thinking\n");
    if (philo->data->num_philos % 2)
        my_usleep(philo, philo->data->time_to_think);
    return (0);
}
