/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:20:11 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/07 14:59:47 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	swap_forks(t_philo *philo)
// {
// 	t_mutex	*tmp;

// 	tmp = philo->left_fork;
// 	philo->left_fork = philo->right_fork;
// 	philo->right_fork = tmp;
// }

int	rip(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	if (data->death)
	{
		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (0);
}

void	*simulation(void *arg)
{
	t_philo	*current_ph;

	current_ph = (t_philo *)arg;
	if (current_ph->ph_id % 2)
		usleep(1000);
	while (current_ph->num_meals < current_ph->data->num_eat)
	{
		if (0 != current_ph->data->num_eat)
			current_ph->num_meals++;
		if (-1 == eating(current_ph))
			return (NULL);
		if (sleeping(current_ph))
			return (NULL);
		if (thinking(current_ph))
			return (NULL);
	}
	return (NULL);
}
