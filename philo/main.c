/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:30:47 by mouahman          #+#    #+#             */
/*   Updated: 2025/05/19 08:45:42 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (5 > ac || 6 < ac)
		return (usage());
	if (-1 == init(&data, ac, av))
		return (printf("wrong inputs\n"), 1);
	data.philos = create_philos(data.num_philos);
	data.fork_mutexes = init_fork_mutex(data.num_philos);
	if (NULL == data.philos || NULL == data.fork_mutexes)
		return (cleanup(&data, 1));
	data.start_time = current_time();
	init_philos(&data);
	if (0 != create_threads(&data))
		return (cleanup(&data, 1));
	if (0 != join_threads(data.philos))
		return (cleanup(&data, 1));
	if (0 != pthread_join(data.waiter, NULL))
		return (cleanup(&data, 1));
	cleanup(&data, 0);
	return (0);
}
