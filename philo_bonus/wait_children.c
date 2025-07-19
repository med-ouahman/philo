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

// static int	died(int stat, t_philo *philo)
// {
// 	if (WIFEXITED(stat))
// 	{
	
// 		printf("%ld %d died\n", time_diff(philo->data->start_time), philo->id);
// 		// lock_printf(philo, "%ld %d died\n");
// 		return (1);
// 	}
// 	return (0);
// }

int	kill_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		kill(data->philos[i].pid, SIGINT);
		i++;
	}
	return (0);
}

int	wait_children(t_data *data)
{
	int		stat;

	waitpid(0, &stat, 0);
	if (WIFEXITED(stat))
		kill_all(data);
	return (0);
}
