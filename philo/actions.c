/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:10:54 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:29 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = current_time();
	pthread_mutex_unlock(&philo->meal_lock);
}

void	my_usleep(t_data *data, int sleep)
{
	long	time;

	time = current_time() + sleep;
	while (current_time() < time)
	{
		if (philo_died(data))
			return ;
		usleep(10);
	}
}

int	eating(t_philo *philo)
{
	request_fork(philo, philo->left_fork);
	if (philo->left_fork == philo->right_fork)
	{
		usleep(philo->data->time_to_die * 1000);
		if (philo_died(philo->data))
			return (release_fork(philo->left_fork), -1);
	}
	if (philo_died(philo->data))
		return (release_fork(philo->left_fork), -1);
	request_fork(philo, philo->right_fork);
	if (philo_died(philo->data))
	{
		release_fork(philo->right_fork);
		release_fork(philo->left_fork);
		return (-1);
	}	
	update_last_meal(philo);
	lock_printf(philo, "%ld %d is eating\n");
	my_usleep(philo->data, philo->data->time_to_eat);
	release_fork(philo->right_fork);
	release_fork(philo->left_fork);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (philo_died(philo->data))
		return (-1);
	lock_printf(philo, "%ld %d is sleeping\n");
	my_usleep(philo->data, philo->data->time_to_sleep);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (philo_died(philo->data))
		return (-1);
	lock_printf(philo, "%ld %d is thinking\n");
	my_usleep(philo->data, philo->data->think);
	return (0);
}
