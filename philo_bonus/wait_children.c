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

int	kill_all(t_data *data, int d)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (d != i)
			kill(data->philos[i].pid, SIGINT);
		i++;
	}
	return (0);
}

static int 	philo_exited(t_philo *philo)
{
	int	stat;

	waitpid(philo->pid, &stat, 0);
	if (WIFEXITED(stat) && WEXITSTATUS(stat) == 1)
	{
		printf("%ld %d died\n", time_diff(philo->data->start_time), philo->id);
		return (1);
	}
	return (0);
}

int	wait_children(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (philo_exited(&data->philos[i]))
			break ;
		i++;
	}
	kill_all(data, i);
	return (0);
}
