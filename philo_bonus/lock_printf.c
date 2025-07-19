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

#include "philo_bonus.h"

int	lock_printf(t_philo *philo, char *format)
{
	sem_post(philo->data->printlock);
	sem_wait(philo->data->printlock);
	printf(format, time_diff(philo->data->start_time), philo->id);
	return (0);
}
