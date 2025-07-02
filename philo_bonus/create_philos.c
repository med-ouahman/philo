/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 10:30:30 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/28 12:18:08 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*create_philos(int num_philos)
{
	t_philo	*philos;

	return (malloc(num_philos * sizeof(*philos)));
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = create_philos(data->num_philos);
	data->forks = sem_open("/forks", 0100, 0644, data->num_philos);
	if (NULL == data->philos)
		return (0);
	i = 0;
	while (data->num_philos > i)
	{
		data->philos[i].last_meal = current_time();
		data->philos[i].pid = -1;
		data->philos[i].id = i + 1;
		data->philos[i].index = i;
		data->philos[i].num_meals = data->num_eat == 0 ? -1: 0;
		data->philos->data = data;
		i++;
	}
	return (0);
}
