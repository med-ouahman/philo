/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimaed_time_to_think.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:36:51 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/07 14:30:42 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_think(t_data *data)
{
	int	time_to_think;

	if (data->num_philos % 2 == 0)
		return (0);
	time_to_think = 0;
	if (data->time_to_eat > data->time_to_sleep)
	{
		time_to_think = data->time_to_eat - data->time_to_sleep + 2;
	}
	else if (data->time_to_eat == data->time_to_sleep)
		time_to_think = data->time_to_eat;
	return (time_to_think);
}
