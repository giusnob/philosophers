#include "philo.h"

void	destroy_forks(t_table *gmu)
{
	int	i;

	i = 0;
	while (i < gmu->philos_number)
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

bool	is_sim_finished(t_table *gmu)
{
	bool	end;
	
	pthread_mutex_lock(&gmu->sim_lock);
	end = gmu->sim_finished;
	pthread_mutex_unlock(&gmu->sim_lock);
	return (end);
}

void	set_sim_finished(t_table *gmu, bool s_finish)
{
	pthread_mutex_lock(&gmu->sim_lock);
	gmu->sim_finished = s_finish;
	pthread_mutex_unlock(&gmu->sim_lock);
}