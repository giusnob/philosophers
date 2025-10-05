#include "philo.h"

size_t	get_n_meals(t_philo *philo)
{
	size_t	n_meal;

	pthread_mutex_lock(&philo->meal_lock);
	n_meal = philo->n_meals;
	pthread_mutex_unlock(&philo->meal_lock);
	return (n_meal);
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
