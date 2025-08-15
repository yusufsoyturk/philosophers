/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:20:27 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/15 13:02:43 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	free_all(t_prog *prog)
{
	int	i;

	i = 0;
	if (prog->forks)
	{
		while (i < prog->num_of_philos)
		{
			pthread_mutex_destroy(&prog->forks[i]);
			i++;
		}
		free(prog->forks);
	}
	pthread_mutex_destroy(&prog->write_lock);
	pthread_mutex_destroy(&prog->meal_lock);
	pthread_mutex_destroy(&prog->dead_lock);
	if (prog->philos)
		free(prog->philos);
}
