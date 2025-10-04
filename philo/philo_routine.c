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

void	print_action(t_philo *philo, t_action act)
{
	size_t	curr_time;
	char	*print;

	if (is_sim_finished(philo->gmu) && ACTION_DEATH != act)
		return ;
	curr_time = current_time() - philo->gmu->start_time;
	if (act == ACTION_DEATH)
		print = "is dead";
	if (act == ACTION_SLEEP)
		print = "is sleeping";
	if (act == ACTION_THINK)
		print = "is thinking";
	if (act == ACTION_EAT)
		print = "is eating";
	if (act == ACTION_TAKE_FORK)
		print = "has taken a fork";
	pthread_mutex_lock(&philo->gmu->print_lock);
	printf("%llu %d %s\n", curr_time, philo->number, print);
	pthread_mutex_unlock(&philo->gmu->print_lock);
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
