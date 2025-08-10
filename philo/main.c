#include "inc/philo.h"

int main(int ac, char **av)
{
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