/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:18:36 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/08/11 15:28:35 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

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
	printf("%ld \n", ft_atol(av[3]));
}