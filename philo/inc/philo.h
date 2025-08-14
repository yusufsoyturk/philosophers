/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:18:59 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/14 12:24:06 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <limits.h>	// INT_MAX
#include <string.h>		// memset
#include <stdio.h>		// printf
#include <stdlib.h>		// malloc, free
#include <unistd.h>		// write, usleep
#include <sys/time.h>   // gettimeofday
#include <pthread.h>	// pthreads için 

typedef struct	s_philo
{
	int				id;
	pthread_t		thread;
	size_t			last_meal; // ölüm zamanı için
	int				meals_eaten; //opsiyonel bölüm için
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
	struct s_prog	*prog;
}				t_philo;

typedef struct s_prog
{
	int				dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	*forks;
	long			num_of_philos;
	long			time_to_eat;
	long			time_to_die;
	long			time_to_sleep;
	long            num_times_to_eat;
	size_t			start_time;
	t_philo			*philos;
}			t_prog;

long	ft_atol(char *str);
int		arg_checker(char **av);
int		arg_val_checker(char **av);
void	ft_init_prog(t_prog *prog, char **av);
void	ft_init_philos(t_prog *prog);
long	ft_get_time();
void	ft_usleep(long time, t_prog *prog);
void	print_event(t_prog *prog, char *msg, int id);
void	*ft_routine(void *args);
void	sleep_and_think(t_philo *philo, t_prog *prog);
void	take_fork(t_philo *philo, t_prog *prog);
void	just_one_philo(t_prog *prog, t_philo *philo);
void	meal_counter(t_philo *philo, t_prog *prog);
void	*monitor(void *args);
int		ft_create_threads(t_prog *prog);

#endif
