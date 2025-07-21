/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:05:06 by mouahman          #+#    #+#             */
/*   Updated: 2025/04/23 08:53:51 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_philo *philos)
{
	int	i;

	if (0 != pthread_join(philos->data->waiter, NULL))
		return (1);
	i = 0;
	while (i < philos->data->num_philos)
	{
		if (0 != pthread_join(philos[i].th_id, NULL))
			return (1);
		i++;
	}
	return (0);
}
