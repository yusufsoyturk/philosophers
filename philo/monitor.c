/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:50:47 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/14 13:06:38 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	*monitor(void *args)
{
	t_prog	*prog;
	long	time;
	int		i;
	int		meal_controller;

	prog = (t_prog *)args;
	i = 0;
	meal_controller = 0;
	time = ft_get_time();
	while (1)
	{
		i = 0;
		time = ft_get_time();
		meal_controller = 0;
		while (i < prog->num_of_philos)
		{
			pthread_mutex_lock(&prog->meal_lock);
			if (time - (long)prog->philos[i].last_meal > prog->time_to_die)
			{
				print_event(prog, "died", prog->philos[i].id);
				prog->dead_flag = 1;
				pthread_mutex_unlock(&prog->meal_lock);
			}
			else
				pthread_mutex_unlock(&prog->meal_lock);
			i++;
		}
		i = 0;
		if (prog->num_times_to_eat > 0)
		{
			pthread_mutex_lock(&prog->meal_lock);
			while (i < prog->num_of_philos)
			{
				if (prog->philos[i].meals_eaten >= prog->num_times_to_eat)
					meal_controller++;
				i++;
			}
			pthread_mutex_unlock(&prog->meal_lock);
			if (meal_controller == prog->num_of_philos)
			{
				prog->dead_flag = 1;
				return (NULL);
			}
		}
		if (prog->dead_flag == 1)
			return (NULL);
	}
	return (NULL);
}
