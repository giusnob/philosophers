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
	custom_usleep(philo->gmu->time_to_eat);
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
	if (philo->number % 2 == 0)
		usleep(50);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = current_time();
	pthread_mutex_unlock(&philo->meal_lock);
	if (philo->gmu->philos_number == 1)
		return ;
	while (!is_sim_finished(philo->gmu))
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		print_action(philo, ACTION_SLEEP);
		custom_usleep(philo->gmu->time_to_sleep);
		print_action(philo, ACTION_THINK);
	}
}
