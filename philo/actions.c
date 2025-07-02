/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 09:10:54 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/02 15:51:44 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	request_fork(philo, philo->left_fork);
	if (philo->left_fork == philo->right_fork)
	{
		usleep(philo->data->time_to_die * 1000);
		if (philo->data->death)
			return (relase_fork(philo->left_fork), -1);
	}
	if (philo->data->death)
		return (relase_fork(philo->left_fork), -1);
	request_fork(philo, philo->right_fork);
	if (philo->data->death)
	{
		relase_fork(philo->right_fork);
		relase_fork(philo->left_fork);
		return (-1);
	}
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->death)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_lock(&philo->data->printlock);
	printf("%ld %d is eating\n", time_diff(philo->data->start_time),
		philo->ph_id);
	pthread_mutex_unlock(&philo->data->printlock);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = current_time();
	pthread_mutex_unlock(&philo->meal_lock);
	relase_fork(philo->right_fork);
	relase_fork(philo->left_fork);
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (philo->data->death)
		return (0);
	pthread_mutex_lock(&philo->data->printlock);
	printf("%ld %d is sleeping\n",
		time_diff(philo->data->start_time), philo->ph_id);
	pthread_mutex_unlock(&philo->data->printlock);
	usleep(philo->data->time_to_sleep * 1000);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (philo->data->death)
		return (0);
	pthread_mutex_lock(&philo->data->printlock);
	printf("%ld %d is thinking\n",
		time_diff(philo->data->start_time), philo->ph_id);
	pthread_mutex_unlock(&philo->data->printlock);
	usleep(1000);
	return (0);
}
