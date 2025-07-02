/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_waiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:27:26 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/28 11:38:47 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	timed_out(t_philo *philo)
{
	if (current_time() -philo->last_meal >= philo->data->time_to_die)
		return (1);
	return (0);
}

static int	check_for_death(t_philo *philo)
{
	int	i;

	i = 0;
	
	if (timed_out(philo))
	{
		philo->data->died = true;
		printf("%ld %d died\n",
			time_diff(-1), philo->id);
		return (1);
	}
	return (0);
}
void	*waiter(void *p)
{

	t_philo	*philo;

	philo = p;
	while (true)
	{
		if (check_for_death(philo))
			return (NULL);
		usleep(1000);
	}
	return (philo);
}

