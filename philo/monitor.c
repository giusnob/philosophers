/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:54:04 by ginobile          #+#    #+#             */
/*   Updated: 2025/10/05 16:54:04 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_philo_full(t_philo *philo)
{
	if (!philo->gmu->meals_to_finish_present)
		return (false);
	return (get_n_meals(philo) >= philo->gmu->meals_to_finish);
}

bool	is_philo_dead(t_philo *philo)
{
	size_t	meal_not_meal;

	pthread_mutex_lock(&philo->meal_lock);
	meal_not_meal = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_lock);
	if (meal_not_meal == 0)
		return (false);
	if (meal_not_meal < current_time() - philo->gmu->time_to_die)
		return (true);
	return (false);
}

void	monitor(t_table *gmu)
{
	int	i;
	int	check_philos_full;

	check_philos_full = 0;
	while (check_philos_full < gmu->philos_number)
	{
		i = -1;
		check_philos_full = 0;
		while (++i < gmu->philos_number)
		{
			if (is_philo_full(&gmu->philos[i]))
				check_philos_full += 1;
			else if (is_philo_dead(&gmu->philos[i]))
			{
				set_sim_finished(gmu, true);
				print_action(&gmu->philos[i], ACTION_DEATH);
				return ;
			}
		}
		usleep(50);
	}
}
