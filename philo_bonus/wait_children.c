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

int	wait_children(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		waitpid(data->philos[i].pid, NULL, 0);
		i++;
	}
	return (0);
}
