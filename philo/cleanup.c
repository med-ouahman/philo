/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouahman <mouahman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:29:55 by mouahman          #+#    #+#             */
/*   Updated: 2025/05/19 08:45:47 by mouahman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	vfree(void **ptr)
{
	if (NULL == *ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

int	cleanup(t_data *data, int code)
{
	vfree((void **)&data->philos);
	vfree((void **)&data->fork_mutexes);
	return (code);
}
