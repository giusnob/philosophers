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
		gmu->philos[i] = (t_philo){0};
		gmu->philos[i].number = i + 1;
		pthread_mutex_init(&gmu->philos[i].meal_lock, NULL);
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
	int	i;

	i = 0;
	gmu->start_time = current_time();
	pthread_mutex_init(&gmu->print_lock, NULL);
	pthread_mutex_init(&gmu->sim_lock, NULL);
	
	while (i < gmu->n_philos)
	{
		pthread_create(&gmu->philos[i].id, NULL, philo_routine, &gmu->philos[i]);
		i++;
	}
	monitor(gmu);
}

void	end_dinner(t_table *gmu)
{
	int	i;

	i = 0;
	while (i < gmu->n_philos)
	{
		pthread_join(gmu->philos[i].id, NULL);
		pthread_mutex_destroy(&gmu->philos[i].meal_lock);
		i++;
	}
	destroy_forks(gmu);
	// clean up
	free(gmu->forks);
	free(gmu->philos);
	pthread_mutex_destroy(&gmu->print_lock);
	pthread_mutex_destroy(&gmu->sim_lock);
}



void	simulation(t_table *gmu)
{
	init_forks(gmu);
	init_philos(gmu);
	start_dinner(gmu);
	end_dinner(gmu);
}
