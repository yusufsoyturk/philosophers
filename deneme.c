#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h> 
#include <unistd.h>

size_t ft_get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int main()
{
	long start, now;

	start = ft_get_time();
	usleep(200000);
	now = ft_get_time();
	printf("%ld\n%ld\n", start, now);
}