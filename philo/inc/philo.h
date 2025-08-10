#ifndef PHILO_H
#define PHILO_H

# include <limits.h>    // INT_MAX
#include <string.h>     // memset
#include <stdio.h>      // printf
#include <stdlib.h>     // malloc, free
#include <unistd.h>     // write, usleep
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
}			t_prog;

long	ft_atol(char *str);
int	arg_checker(char **av);
int	arg_val_checker(char **av);


#endif
