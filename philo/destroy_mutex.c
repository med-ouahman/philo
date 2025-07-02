/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:41:32 by mouahman          #+#    #+#             */
/*   Updated: 2025/05/18 13:46:37 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destory_mutex(t_data *data)
{
	long	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (0 != pthread_mutex_destroy(&data->fork_mutexes[i]))
			return (1);
		i++;
	}
	return (0);
}
