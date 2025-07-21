/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:29:55 by mouahman          #+#    #+#             */
/*   Updated: 2025/05/19 08:45:47 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destory_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->philos[i].meal_lock);
		pthread_mutex_destroy(&data->philos[i].meals);
		i++;
	}
	if (!data->fork_mutexes)
		return (0);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->fork_mutexes[i]);
		i++;
	}
	return (0);
}

int		detach_threads(t_data *data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_detach(data->philos[i].th_id);
		i++;
	}
	pthread_detach(data->waiter);
	return (0);
}

void	vfree(void **ptr)
{
	if (NULL == *ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

int	cleanup(t_data *data, int code)
{
	destory_mutexes(data);
	vfree((void **)&data->philos);
	vfree((void **)&data->fork_mutexes);
	return (code);
}
