/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:18:44 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/14 09:35:59 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	arg_val_checker(char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (av[1] && av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][0] != '+' && (av[i][0] < '0' || av[i][0] > '9'))
				return (1);
			if (j != 0 && av[i][j] && (av[i][j] < '0' || av[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_checker(char **av)
{
	int	i;

	i = 1;
	if (arg_val_checker(av) == 1)
		return (1);
	while (av[i])
	{
		if (ft_atol(av[i]) > INT_MAX || ft_atol(av[i]) < INT_MIN)
			return (1);
		i++;
	}
		
	return (0);
}
