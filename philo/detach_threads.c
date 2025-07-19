/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:48:46 by mouahman          #+#    #+#             */
/*   Updated: 2025/04/30 10:08:16 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	detach_threads(t_data *data, long count)
{
	long	i;

	i = 0;
	while (i < count)
	{
		if (0 != pthread_detach(data->philos[i].th_id))
			return (1);
		i++;
	}
	return (0);
}
