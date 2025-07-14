/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 10:40:56 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/28 12:42:07 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	rip(t_philo *philo)
{
	return philo->num_meals == -1;
}

int routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(10);
	while (philo->num_meals < philo->data->num_eat)
	{
		if (0 != philo->data->num_eat)
			philo->num_meals++;
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}

int	simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].pid = fork();
		if (-1 == data->philos[i].pid)
			return (-1);
		if (0 == data->philos[i].pid)
		{
			routine(&data->philos[i]);
			// pthread_create(&data->philos[i].watcher, NULL, waiter, NULL);
			// pthread_join(data->philos[i].watcher, NULL);
			exit(0);
		}
		i++;
	}
	wait_children(data);
	return (0);
}
