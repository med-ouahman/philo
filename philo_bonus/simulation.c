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

int	get_time_to_think(t_data *data)
{
	if (data->num_philos % 2 == 0)
		return (0);
	if (data->time_to_eat > data->time_to_sleep)
		return (data->time_to_eat - data->time_to_sleep + 2);
	return (data->time_to_eat);
}

int	routine(t_philo *philo)
{
	philo->data->start_time = current_time();
	if (philo->id % 2 == 0)
		usleep(100);
	philo->last_meal = current_time();
	while (philo->num_meals < philo->data->num_eat)
	{
		if (0 != philo->data->num_eat)
			philo->num_meals++;
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	cleanup(philo->data, 0);
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
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	wait_children(data);
	return (0);
}
