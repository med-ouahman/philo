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

int main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (usage());
	init(&data, ac, av);
	time_diff(data.start_time);
	init_philos(&data);
	simulation(&data);
}

