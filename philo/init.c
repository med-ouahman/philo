/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 09:05:25 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/07 13:30:02 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_data *data, int ac, char **av)
{
	data->num_philos = (int)parse_args(av[1]);
	data->time_to_die = (int)parse_args(av[2]);
	data->time_to_eat = (int)parse_args(av[3]);
	data->time_to_sleep = (int)parse_args(av[4]);
	if (-1 == data->num_philos
		|| -1 == data->time_to_die
		|| -1 == data->time_to_eat
		|| -1 == data->time_to_sleep)
		return (-1);
	data->death = false;
	data->philos = NULL;
	data->fork_mutexes = NULL;
	pthread_mutex_init(&data->death_mutex, NULL);
	pthread_mutex_init(&data->printlock, NULL);
	if (6 == ac)
	{
		data->num_eat = (int)parse_args(av[5]);
		if (-1 == data->num_eat)
			return (-1);
	}
	else
		data->num_eat = 0;
	data->think = time_to_think(data);
	return (0);
}
