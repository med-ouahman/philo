/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:31:20 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/27 21:44:31 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	request_fork(t_philo *philo)
{
    if (philo_died(philo))
        return (-1);
    sem_wait(philo->data->meal_sem);
    sem_wait(philo->data->forks);
    lock_printf(philo, "%ld %d has taken a fork\n");
    sem_post(philo->data->meal_sem);
    return (0);
}

int release_forks(t_philo *philo)
{
    sem_post(philo->data->forks);
    sem_post(philo->data->forks);
    return (0);
}
