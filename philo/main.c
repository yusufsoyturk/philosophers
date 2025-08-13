/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:18:36 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/11 18:39:27 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

#include <stdio.h>
#include <pthread.h>

void print_philosopher(t_philo *philo)
{
    printf("Philosopher ID: %d\n", philo->id);
    printf("  Thread ID: %lu\n", (unsigned long)philo->thread);
    printf("  Last Meal Time: %zu\n", philo->last_meal);
    printf("  Meals Eaten: %d\n", philo->meals_eaten);
    printf("  Right Fork Mutex Ptr: %p\n", (void *)philo->r_fork);
    printf("  Left Fork Mutex Ptr: %p\n", (void *)philo->l_fork);
    printf("  Program Pointer: %p\n", (void *)philo->prog);
    printf("\n");
}

void print_program(t_prog *prog)
{
    if (!prog)
    {
        printf("Program pointer is NULL.\n");
        return;
    }

    printf("Program Info:\n");
    printf("  Dead Flag: %d\n", prog->dead_flag);
    printf("  Write Lock Mutex Ptr: %p\n", (void *)&prog->write_lock);
    printf("  Meal Lock Mutex Ptr: %p\n", (void *)&prog->meal_lock);
    printf("  Dead Lock Mutex Ptr: %p\n", (void *)&prog->dead_lock);
    printf("  Forks Mutex Ptr: %p\n", (void *)prog->forks);
    printf("  Number of Philosophers: %ld\n", prog->num_of_philos);
    printf("  Time to Eat: %ld\n", prog->time_to_eat);
    printf("  Time to Die: %ld\n", prog->time_to_die);
    printf("  Time to Sleep: %ld\n", prog->time_to_sleep);
    printf("  Number of Times to Eat: %ld\n", prog->num_times_to_eat);
    printf("  Start Time: %zu\n", prog->start_time);
    printf("\n");

    if (!prog->philos)
    {
        printf("No philosophers to print.\n");
        return;
    }

    for (long i = 0; i < prog->num_of_philos; i++)
    {
        printf("Philosopher #%ld:\n", i + 1);
        print_philosopher(&prog->philos[i]);
    }
}


int main(int ac, char **av)
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
	print_program(&prog);
}