#include "philo.h"

void	destroy_forks(t_table *gmu)
{
	int	i;

	i = 0;
	while (i < gmu->n_philos)
	{
		pthread_mutex_destroy(&gmu->forks[i]);
		i++;
	}
}

size_t	current_time()
{
	struct timeval	tval;

	gettimeofday(&tval, NULL);
	return (tval.tv_sec * 1000 + tval.tv_usec / 1000);
}