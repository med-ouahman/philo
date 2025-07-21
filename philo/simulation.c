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

void	update_meal_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals);
	philo->num_meals++;
	pthread_mutex_unlock(&philo->meals);
}

static void	swap_forks(t_philo *philo)
{
	t_mutex	*tmp;

	tmp = philo->left_fork;
	philo->left_fork = philo->right_fork;
	philo->right_fork = tmp;
}

int	philo_died(t_data *data)
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
	if (current_ph->ph_id % 2 == 0)
		swap_forks(current_ph);
	update_last_meal(current_ph);
	while (!has_eaten(current_ph->data))
	{
		if (current_ph->data->num_eat > 0)
			update_meal_count(current_ph);
		if (eating(current_ph))
			break ;
		if (sleeping(current_ph))
			break ;
		if (thinking(current_ph))
			break ;
	}
	return (NULL);
}
