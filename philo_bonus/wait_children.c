/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:23:20 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/28 12:41:00 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	died(int stat, t_philo *philo)
{
	if (WIFEXITED(stat))
	{
	
		printf("%ld %d died\n", time_diff(philo->data->start_time), philo->id);
		// lock_printf(philo, "%ld %d died\n");
		return (1);
	}
	return (0);
}

int	kill_all(t_data *data, int d)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (i != d)
			kill(data->philos[i].pid, SIGINT);
		i++;
	}
	return (0);
}

int	wait_children(t_data *data)
{
	int		i;
	int		stat;

	i = 0;
	while (i < data->num_philos)
	{
		waitpid(data->philos[i].pid, &stat, 0);
		if (died(stat, &data->philos[i]) || 1)
		{
			break ;
		}
		i++;
	}
	kill_all(data, i);
	return (0);
}
