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

int eating(t_philo *philo)
{
    printf("something is odd %d\n", philo->id);
    request_fork(philo);
    request_fork(philo);
	printf("%ld %d is eating\n", time_diff(-1),
		philo->id);
	release_forks(philo);
	usleep(philo->data->time_to_eat * 1000);
    return (0);
}

int sleeping(t_philo *philo)
{
    printf("%ld %d is sleeping\n", time_diff(-1), philo->id);
    usleep(philo->data->time_to_sleep * 1000);
    return (0);
}

int thinking(t_philo *philo)
{
    printf("%ld %d is thinking\n", time_diff(-1), philo->id);
    return (0);
}

