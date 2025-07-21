/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:51:34 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/10 21:53:33 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_printf(t_philo *philo, char *format)
{
	pthread_mutex_lock(&philo->data->printlock);
	if (philo_died(philo->data))
	{
		pthread_mutex_unlock(&philo->data->printlock);
		return (0);	
	}
	printf(format, time_diff(philo->data->start_time), philo->ph_id);
	pthread_mutex_unlock(&philo->data->printlock);
	return (0);
}
