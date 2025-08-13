/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:45:18 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/13 12:46:39 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	just_one_philo(t_prog *prog, t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_event(prog, "has taken a fork", philo->id);
	ft_usleep(prog->time_to_die, prog);
	pthread_mutex_unlock(philo->r_fork);
}

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

void	*ft_routine(void *args)
{
	t_philo *philo;
	t_prog	*prog;

	philo = (t_philo *)args;
	prog = philo->prog;
	if (prog->num_of_philos == 1)
		just_one_philo(prog, philo);
	while (prog->dead_flag == 0)
	{
		take_fork(philo, prog);
		pthread_mutex_lock(&prog->meal_lock);
		philo->last_meal = ft_get_time();
		philo->meals_eaten ++;
		pthread_mutex_unlock(&prog->meal_lock);
		print_event(prog, "is eating", philo->id);
		ft_usleep(prog->time_to_eat, prog);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		print_event(prog, "is sleeping", philo->id);
		ft_usleep(prog->time_to_sleep, prog);
		print_event(prog, "is thinking", philo->id);
	}
	return (NULL);
}
