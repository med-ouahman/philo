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

static sem_t	*abs_sem_open(char *__name, int val)
{
	return (sem_open(__name, 0100, 0644, val));
}

t_philo	*create_philos(int num_philos)
{
	t_philo	*philos;

	return (malloc(num_philos * sizeof(*philos)));
}

int	init_philos(t_data *data)
{
	int		i;

	data->philos = create_philos(data->num_philos);
	data->forks = abs_sem_open("/forks", data->num_philos);
	data->death_sem = abs_sem_open("/death", 1);
	data->printlock = abs_sem_open("/print", 1);
	data->meal_sem = abs_sem_open("/meal", 1);
	if (NULL == data->philos)
		return (0);
	i = 0;
	while (data->num_philos > i)
	{
		data->philos[i].pid = -1;
		data->philos[i].id = i + 1;
		data->philos[i].num_meals = data->num_eat == 0 ? -1: 0;
		data->philos[i].data = data;
		i++;
	}
	return (0);
}
