/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:44:27 by mouahman          #+#    #+#             */
/*   Updated: 2025/07/19 13:45:33 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	cleanup(t_data *data, int _unl)
{
	sem_close(data->meal_sem);
	sem_close(data->forks);
	sem_close(data->death_sem);
	sem_close(data->printlock);
	free(data->philos);
	if (!_unl)
		exit(0);
	sem_unlink(PRINT);
	sem_unlink(FORKS);
	sem_unlink(TRY_EAT);
	sem_unlink(DEATH);
	return (0);
}
