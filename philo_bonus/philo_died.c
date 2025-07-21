/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_waiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:27:26 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/28 11:38:47 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// static int	timed_out(t_philo *philo)
// {
// 	sem_wait(philo->data->meal_sem);
// 	if (time_diff(philo->last_meal) >= philo->data->time_to_die)
// 	{
// 		sem_post(philo->data->meal_sem);
// 		return (1);
// 	}
// 	sem_post(philo->data->meal_sem);
// 	return (0);
// }

// static int	check_for_death(t_philo *philo)
// {
// 	if (timed_out(philo))
// 	{
// 		exit(1);
// 		return (1);
// 	}
// 	return (0);
// }


int	philo_died(t_philo *philo)
{
	// sem_wait(philo->data->death_sem);
	if (philo->data->time_to_die <= time_diff(philo->last_meal))
	{
		return (1);
	}
	// sem_post(philo->data->death_sem);
	return (0);
}

