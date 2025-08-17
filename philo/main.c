/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:18:36 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/17 11:12:34 by ysoyturk         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_prog	prog;

	memset(&prog, 0, sizeof(prog));
	if (ac != 5 && ac != 6)
	{
		write(2, "Wrong argument count\n", 22);
		return (1);
	}
	if (arg_checker(av) == 1)
	{
		write(2, "Wrong argument value\n", 22);
		return (1);
	}
	ft_init_prog(&prog, av);
	free_all(&prog);
}
