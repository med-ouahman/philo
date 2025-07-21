/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:23:37 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/05 17:39:01 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	int		i;

	if (NULL == data->philos)
		return (1);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->philos[i].meal_lock, NULL);
		pthread_mutex_init(&data->philos[i].meals, NULL);
		data->philos[i].data = data;
		data->philos[i].ph_id = i + 1;
		data->philos[i].index = i;
		data->philos[i].num_meals = 0;
		if (0 == data->num_eat)
			data->philos[i].num_meals = -1;
		data->philos[i].last_meal = current_time();
		data->philos[i].left_fork = &data->fork_mutexes[i];
		data->philos[i].right_fork
			= &data->fork_mutexes[(i + 1) % data->num_philos];
		i++;
	}
	return (0);
}

pthread_mutex_t	*init_fork_mutex(int num_philos)
{
	pthread_mutex_t	*fork_mutexes;
	int				i;

	fork_mutexes = malloc(num_philos * sizeof(pthread_mutex_t));
	if (NULL == fork_mutexes)
		return (NULL);
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&fork_mutexes[i], NULL);
		i++;
	}
	return (fork_mutexes);
}
