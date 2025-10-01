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
