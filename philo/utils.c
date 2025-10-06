/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ginobile <ginobile@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:54:19 by ginobile          #+#    #+#             */
/*   Updated: 2025/10/06 12:04:43 by ginobile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	custom_usleep(size_t milliseconds)
{
	size_t	right_time;

	right_time = current_time() + milliseconds;
	while (current_time() < right_time)
		usleep(50);
}

void	destroy_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philos_number)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

size_t	current_time(void)
{
	struct timeval	tval;

	gettimeofday(&tval, NULL);
	return (tval.tv_sec * 1000 + tval.tv_usec / 1000);
}

bool	is_sim_finished(t_table *table)
{
	bool	end;

	pthread_mutex_lock(&table->sim_lock);
	end = table->sim_finished;
	pthread_mutex_unlock(&table->sim_lock);
	return (end);
}

void	set_sim_finished(t_table *table, bool s_finish)
{
	pthread_mutex_lock(&table->sim_lock);
	table->sim_finished = s_finish;
	pthread_mutex_unlock(&table->sim_lock);
}
