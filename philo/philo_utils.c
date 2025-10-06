/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:54:09 by ginobile          #+#    #+#             */
/*   Updated: 2025/10/06 12:04:43 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (is_sim_finished(philo->table) && ACTION_DEATH != act)
		return ;
	curr_time = current_time() - philo->table->start_time;
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
	pthread_mutex_lock(&philo->table->print_lock);
	printf("%zu %d %s\n", curr_time, philo->number, print);
	pthread_mutex_unlock(&philo->table->print_lock);
}
