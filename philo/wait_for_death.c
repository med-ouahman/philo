/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 08:55:37 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/07 14:31:30 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	timed_out(t_data *data, int i)
{
	pthread_mutex_lock(&data->philos[i].meal_lock);
	if (time_diff(data->philos[i].last_meal) >= data->time_to_die)
	{
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->philos[i].meal_lock);
	return (0);
}

static int	check_for_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (timed_out(data, i))
		{
			lock_printf(&data->philos[i], "%ld %d died\n");
			pthread_mutex_lock(&data->death_mutex);
			data->death = true;
			pthread_mutex_unlock(&data->death_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	has_eaten(t_data *data)
{
	int	i;
	int	eat;

	i = 0;
	eat = 1;
	while (i < data->num_philos)
	{
		if (data->philos[i].num_meals != data->num_eat)
			eat = 0;
		i++;
	}
	return (eat);
}

void	*wait_for_death(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (true)
	{
		if (has_eaten(data) || check_for_death(data))
			return (NULL);
		usleep(50);
	}
	return (NULL);
}
