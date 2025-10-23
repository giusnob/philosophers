/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:54:07 by ginobile          #+#    #+#             */
/*   Updated: 2025/10/20 19:26:34 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	custom_usleep(philo->table->time_to_eat);
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
		usleep(200);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = current_time();
	pthread_mutex_unlock(&philo->meal_lock);
	if (philo->table->philos_number == 1)
	{
		print_action(philo, ACTION_TAKE_FORK);
		return ;
	}
	while (!is_sim_finished(philo->table))
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		print_action(philo, ACTION_SLEEP);
		custom_usleep(philo->table->time_to_sleep);
		print_action(philo, ACTION_THINK);
	}
}
