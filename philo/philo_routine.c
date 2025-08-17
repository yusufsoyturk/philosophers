/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:45:18 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/17 11:12:23 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	take_fork(t_philo *philo, t_prog *prog)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_event(prog, "has taken a fork", philo->id);
		pthread_mutex_lock(philo->l_fork);
		print_event(prog, "has taken a fork", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_event(prog, "has taken a fork", philo->id);
		pthread_mutex_lock(philo->r_fork);
		print_event(prog, "has taken a fork", philo->id);
	}
}

void	sleep_and_think(t_philo *philo, t_prog *prog)
{
	print_event(prog, "is sleeping", philo->id);
	ft_usleep(prog->time_to_sleep, prog);
	print_event(prog, "is thinking", philo->id);
}

void	meal_counter(t_philo *philo, t_prog *prog)
{
	pthread_mutex_lock(&prog->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&prog->meal_lock);
}

static void	philo_loop(t_philo *philo, t_prog *prog)
{
	int	is_dead;

	while (1)
	{
		pthread_mutex_lock(&prog->dead_lock);
		is_dead = prog->dead_flag;
		pthread_mutex_unlock(&prog->dead_lock);
		if (is_dead == 1)
			break ;
		take_fork(philo, prog);
		pthread_mutex_lock(&prog->meal_lock);
		philo->last_meal = ft_get_time();
		pthread_mutex_unlock(&prog->meal_lock);
		print_event(prog, "is eating", philo->id);
		ft_usleep(prog->time_to_eat, prog);
		meal_counter(philo, prog);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		sleep_and_think(philo, prog);
	}
}

void	*ft_routine(void *args)
{
	t_philo	*philo;
	t_prog	*prog;

	philo = (t_philo *)args;
	prog = philo->prog;
	if (prog->num_of_philos == 1)
	{
		just_one_philo(prog, philo);
		return (NULL);
	}
	philo_loop(philo, prog);
	return (NULL);
}
