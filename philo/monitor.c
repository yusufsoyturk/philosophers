/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:50:47 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/17 11:10:24 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

static int	check_death(t_prog *prog, long time)
{
	int	i;

	i = 0;
	while (i < prog->num_of_philos)
	{
		pthread_mutex_lock(&prog->meal_lock);
		if (time - (long)prog->philos[i].last_meal > prog->time_to_die)
		{
			print_event(prog, "died", prog->philos[i].id);
			pthread_mutex_lock(&prog->dead_lock);
			prog->dead_flag = 1;
			pthread_mutex_unlock(&prog->dead_lock);
			pthread_mutex_unlock(&prog->meal_lock);
			return (1);
		}
		pthread_mutex_unlock(&prog->meal_lock);
		i++;
	}
	return (0);
}

static int	check_meals(t_prog *prog)
{
	int	i;
	int	meal_controller;

	i = 0;
	meal_controller = 0;
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
		pthread_mutex_lock(&prog->dead_lock);
		prog->dead_flag = 1;
		pthread_mutex_unlock(&prog->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *args)
{
	t_prog	*prog;
	long	time;

	prog = (t_prog *)args;
	while (1)
	{
		time = ft_get_time();
		if (check_death(prog, time))
			return (NULL);
		if (prog->num_times_to_eat > 0)
		{
			if (check_meals(prog))
				return (NULL);
		}
		pthread_mutex_lock(&prog->dead_lock);
		if (prog->dead_flag)
		{
			pthread_mutex_unlock(&prog->dead_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&prog->dead_lock);
		ft_usleep(50, prog);
	}
	return (NULL);
}
