#ifndef PHILO_H
#define PHILO_H

# include <limits.h>    // INT_MAX
#include <string.h>     // memset
#include <stdio.h>      // printf
#include <stdlib.h>     // malloc, free
#include <unistd.h>     // write, usleep
#include <sys/time.h>   // gettimeofday
#include <pthread.h>	// pthreads için 

long	ft_atol(char *str);
int	arg_checker(char **av);
int	arg_val_checker(char **av);


#endif
