/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 07:54:05 by mouahman          #+#    #+#             */
/*   Updated: 2025/05/18 13:42:09 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	request_fork(t_philo *philo, pthread_mutex_t *fork_mutex)
{
	if (0 != pthread_mutex_lock(fork_mutex))
		return (1);
	lock_printf(philo, "%ld %d has taken a fork\n");
	return (0);
}

int	release_fork(pthread_mutex_t *fork_mutex)
{
	return (pthread_mutex_unlock(fork_mutex));
}
