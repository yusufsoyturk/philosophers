/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:25:50 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/13 10:04:36 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	ft_init_philos(t_prog *prog)
{
	int	i;

	i = 0;
	prog->philos = malloc(sizeof(t_philo) * prog->num_of_philos);
	while (i < prog->num_of_philos)
	{
		prog->philos[i].id = i + 1;
		prog->philos[i].last_meal = prog->start_time;
		prog->philos[i].meals_eaten = 0;
		prog->philos[i].r_fork = &prog->forks[i];
		prog->philos[i].l_fork = &prog->forks[(i + prog->num_of_philos - 1) % prog->num_of_philos];
		prog->philos[i].prog = prog;
		i++;
	}
}

void	ft_init_prog(t_prog *prog, char **av)
{
	int	i;

	i = 0;
	prog->dead_flag = 0;
	prog->num_of_philos = ft_atol(av[1]);
	prog->time_to_die = ft_atol(av[2]);
	prog->time_to_eat = ft_atol(av[3]);
	prog->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		prog->num_times_to_eat = ft_atol(av[5]);
	prog->start_time = ft_get_time();
	pthread_mutex_init(&prog->write_lock, NULL);
	pthread_mutex_init(&prog->meal_lock, NULL);
	pthread_mutex_init(&prog->dead_lock, NULL);
	prog->forks = malloc(sizeof(pthread_mutex_t) * prog->num_of_philos);
	while (i < prog->num_of_philos)
	{
		pthread_mutex_init(&prog->forks[i], NULL);
		i++;
	}
	ft_init_philos(prog);
}
