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

int	time_to_think(t_data *data)
{
	if (data->num_philos % 2 == 0)
		return (0);
	return (0);
}

int	rip(t_philo *philo)
{
	return (philo->data->died);
}

int	routine(t_philo *philo)
{	
	if (philo->id % 2 == 0)
		usleep(10);
	philo->data->start_time = current_time();
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
			update_last_meal(&data->philos[i]);
			routine(&data->philos[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	wait_children(data);
	return (0);
}
