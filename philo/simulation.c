#include "philo.h"

void	init_forks(t_table *gmu)
{
	int	i;

	i = 0;
	gmu->forks = (t_mutex *)malloc(sizeof(t_mutex) * gmu->n_philos);
	if (!gmu->forks)
		error_exit(gmu);
	while (i < gmu->n_philos)
	{
		pthread_mutex_init(&gmu->forks[i], NULL);
		i++;
	}
}

void	init_philos(t_table *gmu)
{
	int i;

	i = 0;
	gmu->philos = (t_philo *)malloc(sizeof(t_philo) * gmu->n_philos);
	if (!gmu->philos)
		error_exit(gmu);
	while (i < gmu->n_philos)
	{
		if (i == gmu->n_philos - 1)
		{
			gmu->philos[i].right_fork = &gmu->forks[i];
			gmu->philos[i].left_fork = &gmu->forks[0];
		}
		else
		{
			gmu->philos[i].left_fork = &gmu->forks[i];
			gmu->philos[i].right_fork = &gmu->forks[i + 1];
		}
		gmu->philos[i].gmu = gmu;
		i++;
	}
}

void	start_dinner(t_table *gmu)
{
	
}

void	end_dinner(t_table *gmu)
{
	// wait for other philos
	destroy_forks(gmu);
}

void	simulation(t_table *gmu)
{
	init_forks(gmu);
	init_philos(gmu);
	start_dinner(gmu);
	end_dinner(gmu);
}
