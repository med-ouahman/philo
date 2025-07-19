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
        if (waiter(philo))
            return (1);
        usleep(10);
    }
    if (waiter(philo))
        return (1);
    return (0);
}

int eating(t_philo *philo)
{
    if (philo->data->num_philos == 1)
    {
        request_fork(philo);
        my_usleep(philo, philo->data->time_to_die);
    }
    waiter(philo);
    if (request_fork(philo))
    {
        sem_post(philo->data->forks);
        exit(1);
    }
    waiter(philo);
    if (request_fork(philo))
    {
        release_forks(philo);
        exit(1);
    }
    update_last_meal(philo);
    lock_printf(philo, "%ld %d is eating\n");
    my_usleep(philo, philo->data->time_to_eat);
	release_forks(philo);
    return (0);
}

int sleeping(t_philo *philo)
{
    waiter(philo);
    if (rip(philo))
        exit(1);
    lock_printf(philo, "%ld %d is sleeping\n");
    my_usleep(philo, philo->data->time_to_sleep);
    return (0);
}

int thinking(t_philo *philo)
{
    waiter(philo);
    if (rip(philo))
        exit(1);
    lock_printf(philo, "%ld %d is thinking\n");
    if (philo->data->num_philos % 2)
        my_usleep(philo, philo->data->time_to_eat);
    return (0);
}
