/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:54:36 by mouahman          #+#    #+#             */
/*   Updated: 2025/05/18 08:12:25 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_philos(int num_philos)
{
	return (malloc(num_philos * sizeof(t_philo)));
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	if (0 != pthread_create(&data->waiter, NULL, wait_for_death, data))
		return (1);
	while (i < data->num_philos)
	{
		if (0 != pthread_create(&data->philos[i].th_id,
				NULL,
				simulation,
				&data->philos[i]))
			return (1);
		i++;
	}
	return (0);
}
