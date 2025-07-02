/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:20:11 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/02 15:19:43 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	swap_forks(t_philo *philo)
{
	t_mutex	*tmp;

	tmp = philo->left_fork;
	philo->left_fork = philo->right_fork;
	philo->right_fork = tmp;
}

static int	check_death(t_data *data)
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
	if (current_ph->ph_id == current_ph->data->num_philos - 1)
		swap_forks(current_ph);
	if (0 == current_ph->ph_id % 2)
		usleep(1000);
	while (current_ph->num_meals < current_ph->data->num_eat)
	{
		if (0 != current_ph->data->num_eat)
			current_ph->num_meals++;
		if (current_ph->num_meals == current_ph->data->num_eat)
			return (NULL);
		if (check_death(current_ph->data))
			return (NULL);
		if (-1 == eating(current_ph))
			return (NULL);
		if (check_death(current_ph->data))
			return (NULL);
		sleeping(current_ph);
		if (check_death(current_ph->data))
			return (NULL);
		thinking(current_ph);
	}
	return (NULL);
}
