#include "philo.h"

void	take_forks(t_philo *philo)
{

}

void	eat(t_philo *philo)
{

}

void	release_forks(t_philo *philo)
{

}

void	philo_routine(t_philo *philo)
{
	while (!is_sim_finished(philo->gmu))
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		print_action(philo, ACTION_SLEEP);
		usleep(philo->gmu->time_to_sleep * 1000);
		print_action(philo, ACTION_THINK);
	}
}
