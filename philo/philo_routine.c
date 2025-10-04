#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, ACTION_TAKE_FORK);
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, ACTION_TAKE_FORK);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = current_time();
	pthread_mutex_unlock(&philo->meal_lock);
	print_action(philo, ACTION_EAT);
	usleep(philo->gmu->time_to_eat * 1000);
	pthread_mutex_lock(&philo->meal_lock);
	philo->n_meals++;
	pthread_mutex_unlock(&philo->meal_lock);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_routine(t_philo *philo)
{
	if (philo->gmu->n_philos == 1)
		return ;
	if (philo->number % 2 == 0)
		usleep(50);
	while (!is_sim_finished(philo->gmu))
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		if (philo->gmu->meals_to_finish_present
			&& get_n_meals(philo) >= philo->gmu->meals_to_finish)
			break ;
		print_action(philo, ACTION_SLEEP);
		usleep(philo->gmu->time_to_sleep * 1000);
		print_action(philo, ACTION_THINK);
	}
}
