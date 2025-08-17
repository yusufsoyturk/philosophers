/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:03:45 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/17 11:09:39 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long time, t_prog *prog)
{
	long	start;
	int		dead;

	start = ft_get_time();
	while (1)
	{
		pthread_mutex_lock(&prog->dead_lock);
		dead = prog->dead_flag;
		pthread_mutex_unlock(&prog->dead_lock);
		if (dead != 0)
			break ;
		if (ft_get_time() - start >= time)
			break ;
		usleep(100);
	}
}

void	print_event(t_prog *prog, char *msg, int id)
{
	size_t	time;
	int		is_dead;

	time = ft_get_time();
	pthread_mutex_lock(&prog->dead_lock);
	is_dead = prog->dead_flag;
	pthread_mutex_unlock(&prog->dead_lock);
	if (is_dead == 0)
	{
		pthread_mutex_lock(&prog->write_lock);
		printf("%zu %d %s\n", time - prog->start_time, id, msg);
		pthread_mutex_unlock(&prog->write_lock);
	}
}
