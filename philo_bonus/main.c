/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:42:13 by mouahman          #+#    #+#             */
/*   Updated: 2025/06/27 21:39:27 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_data(t_data *data)
{
	printf("Number of philosophers: %d\n\
time_to_die: %d\n\
time_to_eat: %d\n\
time_to_sleep: %d\n\
Number of times each philo must eat: %d\n\
",
		data->num_philos,
		data->time_to_die,
		data->time_to_eat,
		data->time_to_sleep,
		data->num_eat
	);
}

int main(int ac, char **av)
{
	t_data	data;

	sem_unlink("/print");
	sem_unlink("/death");
	sem_unlink("/forks");
	sem_unlink("/try_eat");
	if (ac < 5 || ac > 6)
		return (usage());
	init(&data, ac, av);
	init_philos(&data);
	simulation(&data);
	cleanup(&data, 1);
	// sem_post(data.meal_sem);
}

